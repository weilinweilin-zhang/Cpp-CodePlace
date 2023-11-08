# 组合模式
类似 树状结构，子类与子类之间可以相关包含

类似层次化管理（也是树结构）

通过component 基类，leaf和composite 继承，然后composite 包含component容器，这个在composite拓展更多的 组合和叶子节点。

// 延伸拓展 ：可以父子节点 然后 weakptr 子指向父， shareptr 父指向子。
