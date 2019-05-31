#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <sys/stat.h>

#define CGROUP_PATH "/sys/fs/cgroup/pids/container/"
#define concat(a, b) (a"" b)
#define lambda(body) [](void *args)->int { body; };

void write_rule(const char* path, const char* value) {
    int fd = open(path, O_WRONLY | O_APPEND);
    write(fd, value, strlen(value));
    close(fd);
}

void limit_process_creation() {
    mkdir(CGROUP_PATH, S_IRUSR | S_IWUSR); // 创建具有读写权限的指定文件夹
    const char* pid = std::to_string(getpid()).c_str(); // 转换pid的格式

    // 在CGROUP_PATH文件夹下写入相应规则
    write_rule(concat(CGROUP_PATH, "pids.max"), "5"); // 设置最大可创建进程数量
    write_rule(concat(CGROUP_PATH, "notify_on_release"), "1");
    write_rule(concat(CGROUP_PATH, "cgroup.procs"), pid);
}

void setup_var() {
    clearenv();
    setenv("TERM", "xterm-256color", 0);
    setenv("PATH", "/bin/:/sbin/:usr/bin/:/usr/sbin", 0);
}

void set_host_name(std::string hostname) {
    sethostname(hostname.c_str(), hostname.size());
}

void setup_root(const char* folder) {
    chroot(folder);
    chdir("/");
}

char* allocation() { // 分配栈空间
    const int size = 65536;
    auto *stack = new (std::nothrow) char[size];

    if (stack == nullptr) {
        printf("Cannot allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    return stack + size;
}

int fetch(int status, const char* msg) { // 拉取状态
    if (status == -1) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return status;
}

template <typename... T>
int run(T... parameters) {
    char *args[] = {(char*)parameters..., (char*)0};
    execvp(args[0], args);
    perror("execvp");
    return 0;
}

template <typename T>
void clone_process(T&& func, int flags) {
    auto pid = fetch(clone(func, allocation(), flags, 0), "clone");
    wait(nullptr); // 等待子进程退出
}

int create_process(void *args) { // 创建进程
    limit_process_creation(); // 限制进程的创建
    printf("----> Child pid is: %d\n", getpid());
    set_host_name("m4"); // 设置主机名
    setup_var(); // 设置环境变量
    setup_root("./root"); // 切换到root路径
    mount("proc", "/proc", "proc", 0, 0); // 挂载proc文件系统
    auto run_ = lambda(run("/bin/sh"))
    clone_process(run_, SIGCHLD); // 复制进程
    umount("/proc"); // 执行完成后卸载proc文件系统
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    printf("----> Parent pid is: %d\n", getpid());
    clone_process(create_process, CLONE_NEWPID | CLONE_NEWUTS | SIGCHLD);

    return 0;
}

