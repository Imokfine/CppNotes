## Namespace 命名空间

**namespace** 是C++中的关键字，用来定义一个命名空间，以解决合作开发时的命名冲突问题。

![](image_1.53f992d5.png)

  


注：推荐在函数内部声明 std。如果将 std 直接声明在所有函数外部，这样虽然使用方便，但在中大型项目开发中是不被推荐的，这样做增加了命名冲突的风险。Do not put a using-directive into a header file.

