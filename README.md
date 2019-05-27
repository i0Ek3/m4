# m4docker

Do you know the Docker? Yeah, it is a famous container. But honestly, m4docker just a tiny container, I mean it is a demo, in order to learn how container to work.

## Process

- Use clone() to create the child process
- `/sys/fs/cgroup` always use to mount cgfs


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


