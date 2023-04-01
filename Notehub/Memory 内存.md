## Memory layout of Program



![](image_1.f7021e24.png)





## Allocating memory 内存分配

### Statically allocated memory 静态分配内存

- Automatic variables, such as doing int A; , are allocated on the stack. They only exist for the lifetime of the closest set of enclosing braces.
- We also statically allocate arrays. In C++ we will prefer to use STL containers such as std::array




### Dynamic allocation of memory 动态分配内存

- new，new\[\]，delete，delete\[\] （Use these instead of malloc and free in C）
- new (and malloc) allocate memory on the Heap (or Free-store).
- In C++ we can use STL containers such as std::vector when we cannot know the size at compile time.






-----
**Unmapped** area contains cmd line args and env vars.



**Stack** contains automatic variables













**Heap** contains dynamically allocated memory.







**Data** segments contain global and static variables.







**Text** segment is read only and contains the executable code.

