## Lifetime

- **Automatic**: an object is created when its definition is encountered and destroyed when its name goes out of scope. Sometimes called automatic objects. These are allocated on the stack.
- **Static**: Objects declared in global or namespace scope (see later) and statics declared in functions or classes are created and “live” until the program terminates
- **Heap (or Free store)**: The new and delete operators, create & release objects allocated on the heap (same as malloc in C).
- **Temporary objects** (e.g., intermediate results in a computation). If they are bound to a reference (see later), their lifetime is that of the reference; otherwise, they “live” until the end of the full expression of which they are part.
- **Thread-local objects**: that is, objects declared thread local: such objects are created and destroyed when their thread is.




## 4 ways to initialise a basic type

```c++
int a1 {1}; //uniform intialisation (or “braced initialisation”)
```

```c++
 int a2 = {2};
```

```c++
 int a3 = 3;
```

```c++
 int a4(4);
```

Uniform initialisation does not allow narrowing. Using {} to prevent narrowing

