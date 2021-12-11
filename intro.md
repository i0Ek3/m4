# Introduction 

## 基本介绍

Docker 是用 Go 语言进行开发实现的，基于 Linux 内核的 cgroup，namespace，以及 AUFS 类的 UnionFS 等技术，对进程进行封装隔离，属于操作系统层面的虚拟化技术。 由于隔离的进程独立于宿主和其它的隔离的进程，因此也称其为容器。Docke 最初实现是基于 LXC。

容器就是可以将软件打包成标准化单元，以用于开发、交付和部署的一种工具，而 m4 是为了了解容器的基本运作流程而设计的。

虚拟机和容器是比较相似的两个概念，但是虚拟机是对真是的操作系统的一直给你封装，运行在物理设备上，利用硬件抽象层建立和运行虚拟机体系。

##  Linux Namespace API

> namespace 主要用于进程隔离。

- clone 用于创建一个新进程

- setns 用于将一个进程重新加入一个已经存在的 Namespace

- unshare 用于将调用进程移动到新的 Namespace

## cgroups

> 主要用于资源的限制。

- memory
- hugetlb
- cpu
- innodb_lock_wait_timeout
- net_cls
- devices
- freezer
- perf_event
- pids

## Union File System(UFS)

> UFS 作为存储驱动，是一种栈式叠加的文件系统，其允许在基础的文件系统上，增量式的增加文件。或者理解为将初始化工作打包为一个基本流程，以增量的方式对文件进行修改调用。

比如 Docker 的镜像分层，就是通过 AUFS(Advanced Multi-layered unification filesytem) 的分层结构、挂载等方式来是实现的。

## Docker 的优点

- 更快的交付和部署
- 高效的部署和扩容
- 高效的资源利用率
- 管理简单


## 总结

Docker 中，通过 Linux Namespace 进行网络、进程空间、命名空间等资源的隔离，使用 Cgroups 技术对资源的占用、使用量进行限制，使用 AUFS 等存储驱动来实现分层结构、增量更新等能力。


## Reference

- [https://kknews.cc/code/k2qpn6p.html](https://kknews.cc/code/k2qpn6p.html)
- [https://blog.lizzie.io/linux-containers-in-500-loc.html](https://blog.lizzie.io/linux-containers-in-500-loc.html)
- [https://zhuanlan.zhihu.com/p/434731896](https://zhuanlan.zhihu.com/p/434731896)
- [https://moelove.info/2021/12/10/搞懂容器技术的基石-namespace-上/](https://moelove.info/2021/12/10/搞懂容器技术的基石-namespace-上/)
