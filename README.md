# m4

> A simple tiny docker.

Do you know the Docker? Yeah, it is a famous container. But honestly, m4 just a tiny container, I mean it is a demo, in order to learn how container to work.


## Points

- Use clone() system call to create the child process
- Use execvp() to load a program with `/bin/sh`
- Use clearenv() to remove environment variables
- Use UTS Linux namespaces 
- `/sys/fs/cgroup` always use to mount cgfs


## Usage

**Note: You'd better run this program under the Linux.**

You can build this program by `make` command or run follows command alone under the src/:

```Shell
$ gcc -I ../include m4.cpp -o m4 -std=c++11
```


## Screenshot

![](https://github.com/i0Ek3/m4/tree/blob/master/pic/m4.png)


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

Big thanks to César Valdez for his tutorial.

