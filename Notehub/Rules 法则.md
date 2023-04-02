### Rule of 0 零法则

- If you can avoid defining default operations, do
- If you define or =delete any default operation, define or =delete them all
- 有自定义析构函数、复制/移动构造函数或复制/移动赋值运算符的类应该专门处理所有权（这遵循单一责任原则）。其他类都不应该拥有自定义的析构函数、复制/移动构造函数或复制/移动赋值运算符
- 如果一个类不管理资源，那么它不应该有复制构造函数、移动构造函数、复制赋值运算符、移动赋值运算符或析构函数。相反，它应该依赖编译器提供的默认实现。（在 C++ 中，资源是任何需要手动分配、初始化和释放的东西，例如动态分配的内存、文件句柄、网络连接或任何其他外部资源。管理资源意味着对其生命周期负责，包括分配、初始化和释放。）



### Rules of 3 三法则

- If a class requires any user-defined implementation of a **destructor**, **copy** **constructor** or **copy assignment operator**, it almost certainly requires all three.
- 若某个类需要用户定义的**析构函数（destructor）**、用户定义的**复制构造函数（copy constructor）**或用户定义的**复制赋值运算符（copy assignment operator）**，则它几乎肯定三者全部都需要。



Rules of 5 五法则

- If move semantics are desired, we add **move constructor** and **move assignment operator** to the above list.
- 如果一个类具有**移动构造函数**或**移动赋值运算符**，那么它还应该定义**复制构造函数**、**复制赋值运算符**和**析构函数**。这是因为移动操作通常是根据复制操作定义的，确保所有五个功能一起正确工作很重要。

```c++
class mydef
{
Public:
 mydef()                        = default;  // Default constructor
 
 ~mydef()                       = default;  // Destructor
 mydef(const mydef&)            = default;  // Copy constructor
 mydef(mydef&&)                 = default;  // Move constructor
 mydef& operator=(const mydef&) = default;  // copy assignment
 mydef& operator=(mydef&&)      = default;  // move assignment
};
```


