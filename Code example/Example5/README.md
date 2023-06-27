## Readme

To run the program, load the related module first

```bash
module load boost/1_72_0_openmpi_3.1.5-gnu
```

Compile the code using makefile

```bash
make
```

For Q1, run

```bash
./assignment5a
```

For Q2, run

```bash
./assignment5b
```

For Q3, run

```bash
mpirun -n 3 ./assignment5a
```



## Q4. Written Questions

### A) Timings. Q1 & Q2 (5)
#### (i) For Q1

* **async policy**

![image](https://github.com/Imokfine/CppNotes/assets/98553439/565d9aee-a837-4412-a22c-5cc6a2da71da)


* **deferred policy**

![image](https://github.com/Imokfine/CppNotes/assets/98553439/51908651-4b06-4ea2-a088-85aa94d9e4ef)


I use 3 threads in the code. 

As we can see that, when using async policy, the running time of serial version is over 3 times longer than parallel version, and the running time of two parallel version programs are similar.

When using defferred policy, the running time of async is longer than packaged task but shorter than serial version.

When we use the async policy, the task or parallel execution structure will be launched asynchronously. The deferred policy defers the execution of the task or parallel execution structure until explicitly requested. If we do not specify a policy explicitly , the default policy used depends on the particular parallelism construct we're using.

#### (ii) For Q2

* **-O0 level**

  * **asnyc policy**

    ![image](https://github.com/Imokfine/CppNotes/assets/98553439/b060e82a-b255-4436-a633-12ba290fe505)


  * **deferred policy**

    ![image](https://github.com/Imokfine/CppNotes/assets/98553439/f5aa2764-758f-4cdb-935a-6f334d54b3ce)


* **-O3 level**

  * **async policy**

    ![image](https://github.com/Imokfine/CppNotes/assets/98553439/01fab40f-2409-4e29-b358-650692f8f238)


  * **deferred policy**

    ![image](https://github.com/Imokfine/CppNotes/assets/98553439/4084f6ad-2d79-4272-9112-d2dc260b5dd2)


Using deferred policy tend to be faster. For async policy, -O3 level has better performance.



### B) Plots for Q2 (5)

The file points.txt is too large, so I display the plot of these points alone

![image](https://github.com/Imokfine/CppNotes/assets/98553439/8a1e9b0b-c01b-4a77-8632-303eea3a8205)




* **Not merged**

  ![image](https://github.com/Imokfine/CppNotes/assets/98553439/45d0a867-264c-44fe-b03b-14a6601b9f75)


* **After first merge**

  ![image](https://github.com/Imokfine/CppNotes/assets/98553439/61af2b1d-a8c2-46f4-b767-dcea81ed216b)


* **After second merge**

 ![image](https://github.com/Imokfine/CppNotes/assets/98553439/bed74e37-270b-48ae-9f4a-5bfa515acb45)


