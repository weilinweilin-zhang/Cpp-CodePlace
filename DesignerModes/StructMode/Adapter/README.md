# 适配器
使接口不兼容对象能够相互合作，做法是将类自己的接口包裹在一个已存在的类中（也可以是继承方式作妖兼容)

## 实现剖析

一个功能代码，只能传A 进去，然后有个B也想要适用这个功能代码，这时候就可以创建一个C的类来继承A这个类，（秉承着is-a原则，功能代码肯定兼容C），这时候C（也就是适配器）可以在内部定义B的变量，然后整功能代码需要参数信息，就可以完成转化。

其实可以不用继承，C可以重载几个创建函数，只不过 功能代码得改成C这种类型，兼容多个类型。