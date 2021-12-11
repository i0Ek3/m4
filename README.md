# m4

> A tiny container hybird programming by C and C++.

m4 is a tiny container, I mean it's just a demo, in order to learn how does container created and worked. And now, I get it!

> Reference partial introduction [here](https://github.com/i0Ek3/m4/blob/master/doc/intro.md).

## Points

- `clone()/fork()` to create the process
- `exec()` to load a binary image
- `clearenv()` to remove environment variables
- `UTS(Universal Time Sharing)` namespace use to implement basic ioslation
- `chroot()` to change the root directory
- `mount` & `unmount` /proc before start and exit container
- `cgroup(/sys/fs/cgroup)` to implement Linux resource isolation
    - when we run command `sudo mkdir -p /sys/fs/cgroup/pids/container/`, cgroup will generates follows files: cgroup.clone_children, cgroup.procs, notify_on_release, pids.current,  pids.events, pids.max, tasks. And someone need us to modify.

## Usage

**Note: You'd better run this program under the Linux.**

You can build this program by `make` command or run follows command alone under the src/:

```Shell
$ g++ -I ../include m4.cpp -o m4 -std=c++11
```

## Screenshot

![](https://github.com/i0Ek3/m4/blob/master/m4.png)


## Problems

- How to isolate shell process? `Using getpid() and CLONE_NEWPID flag in clone()`
- How to isolate the folders process can access? `Using chroot() and chdir()`
- How to limiting process ceration? `Linux Control Group or cgroup`
- How about performance? `Set the cgroup rules to control container consume`
- What’s the difference between VM and Containers? `I think containers faster than VM cause of you just run only your process and it's dependencies in container, but in VM, you need to executing a bunch of OS libraries on the top, which need more overhead`

## Credit

Big thanks to César Valdez for his [tutorial](http://cesarvr.github.io/post/2018-05-22-create-containers/).

## References

- [http://www.alloyteam.com/2019/07/13885/](http://www.alloyteam.com/2019/07/13885/)
- [https://www.ibm.com/developerworks/cn/linux/1506_cgroup/index.html](https://www.ibm.com/developerworks/cn/linux/1506_cgroup/index.html)
