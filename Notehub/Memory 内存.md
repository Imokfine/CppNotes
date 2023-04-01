## Memory layout of Program
![1680372003248](https://user-images.githubusercontent.com/98553439/229306954-b283211d-431f-4547-b789-ed3258fde98f.png)

## Allocating memory 内存分配

### Statically allocated memory 静态分配内存

- Automatic variables, such as doing int A; , are allocated on the stack. They only exist for the lifetime of the closest set of enclosing braces.
- We also statically allocate arrays. In C++ we will prefer to use STL containers such as std::array




### Dynamic allocation of memory 动态分配内存

- new，new\[\]，delete，delete\[\] （Use these instead of malloc and free in C）
- new (and malloc) allocate memory on the Heap (or Free-store).
- In C++ we can use STL containers such as std::vector when we cannot know the size at compile time.
