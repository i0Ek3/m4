# m4

A simple tiny container.

> Reference partial introduction [here](https://github.com/i0Ek3/m4/blob/master/doc/intro.md).

## Points

- Linux namespace/Cgroups/UFS
- Use clone() system call to create the child process
- Use execvp() to load a program with `/bin/sh`
- Use clearenv() to remove environment variables
- `/sys/fs/cgroup` always use to mount cgfs


## Usage

**Note: You'd better run this program under the Linux.**

You can build this program by `make` command or run follows command alone under the src/:

```Shell
$ gcc -I ../include m4.cpp -o m4 -std=c++11
```


## Screenshot

![](https://github.com/i0Ek3/m4/blob/master/pic/m4.png)


## Problems

- How to isolate shell process?
    
    use getpid() and CLONE_NEWPID flag in clone()

- How to isolate the folders process can access?

    using chroot() and chdir()

- How to limiting process ceration?

    Linux Control Group or cgroup

- How about performance?

    Good, you can set the cgroup rules to control container consume

- What’s the difference between VM and Containers?

    I think containers faster than VM cause of you just run only your process and it's dependencies in container, but in VM, you need to executing a bunch of OS libraries on the top, which need more overhead.

## Credit

Big thanks to César Valdez for his [tutorial](http://cesarvr.github.io/post/2018-05-22-create-containers/).

## References

- [http://www.alloyteam.com/2019/07/13885/](http://www.alloyteam.com/2019/07/13885/)
- [https://www.ibm.com/developerworks/cn/linux/1506_cgroup/index.html](https://www.ibm.com/developerworks/cn/linux/1506_cgroup/index.html)
