## Different types of scope in C++

- **Local** scope: Something declared between curly braces {} in a function only has scope within those braces.
- **Class** scope: A class member name has scope between the {} at the start and end of the class declaration.
- **Namespace** scope: A name declared within a Namespace has scope within that Namespace. It can be accessed from outside the namespace using :: which is the scope resolution operator.
- **Global** scope: A name is a global name if it is defined outside of of any function, class, enum class or namespace.
- **Statement** scope. A name defined within the () of an if, for or switch statement.



## Scope solution operator 域解析操作符

双冒号 **:: **操作符被称为域解析操作符(scope solution operator)，含义和用法如下：

1. 在类外部声明成员函数。

```c++
void Point::Area(){};
```

2. 调用全局函数；表示引用成员函数变量及作用域，作用域成员运算符

例：

```c++
System::Math::Sqrt()
```

相当于

```c
System.Math.Sqrt()
```

3. 调用类的静态方法，如：

```c++
 CDisplay::display()
```




把域看作是一个可视窗口全局域的对象在它被定义的整个文件里，一直到文件末尾都是可见的。在一个函数内被定义的对象是局域的（local scope）， 它只在定义其的函数体内可见。每个类维持一个域，在这个域之外 ，它的成员是不可见的。类域操作符告诉编译器后面的标识符可在该类的范围内被找到。



## Declarations vs Definitions 声明 vs 定义

Declaration 声明

```c++
Student (string s);
```

### Definition 定义

```c++
Student (string s){
  Std::cout << " I am " << s << std::endl;

  }


```



注：头文件只能放declaration，不能放definition



## Initialization vs Assignment 初始化 vs 赋值

### Initialization 初始化

```c++
Student::Student (string s) : name(s){}
```

### Assignment 赋值

```c++
Student::Student (string s){name = s;}
```

