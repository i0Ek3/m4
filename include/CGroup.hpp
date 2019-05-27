#ifndef CGROUP_HPP
#define CGROUP_HPP

#include <string>
#include <ofstream>

class CGroup
{
public:
    CGroup(std::string folder)
        : folderName{folder}
    {
        mkdir(folder.c_str(), S_IRUSR | S_IRUSR);
    }

    template <typename T> 
    void write(std::string file, T value) {
        os.open(folderName + file, std::ofstream::out | std::ofstream::app);
        os << value;
        os.close();
    }

private:
    std::string folderName;
    std::ofstream os;
};

void limit_process_creation_() {
    mkdir(CGROUP_PATH, S_IRUSR | S_IWUSR);
    CGroup cgroup{CGROUP_PATH};

    cgroup.write("pids.max", 5);
    cgroup.write("notify_on_release", 1);
    cgroup.write("cgroup.procs", getpid());
}


#endif


