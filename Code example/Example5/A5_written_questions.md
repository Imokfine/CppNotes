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

For Q1, run

```bash
mpirun -n 3 ./assignment5a
```



## Q4. Written Questions

### A) Timings. Q1 & Q2 (5)
#### (i) For Q1

* **async policy**

![image-20230520221314806](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230520221314806.png)

* **deferred policy**

![image-20230520221456449](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230520221456449.png)

I use 3 threads in the code. 

As we can see that, when using async policy, the running time of serial version is over 3 times longer than parallel version, and the running time of two parallel version programs are similar.

When using defferred policy, the running time of async is longer than packaged task but shorter than serial version.

When we use the async policy, the task or parallel execution structure will be launched asynchronously. The deferred policy defers the execution of the task or parallel execution structure until explicitly requested. If we do not specify a policy explicitly , the default policy used depends on the particular parallelism construct we're using.

#### (ii) For Q2

* **-O0 level**

  * **asnyc policy**

    ![image-20230517162159849](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230517162159849.png)

  * **deferred policy**

    ![image-20230517161951755](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230517161951755.png)

* **-O3 level**

  * **async policy**

    ![image-20230517161637595](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230517161637595.png)

  * **deferred policy**

    ![image-20230517161720810](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230517161720810.png)

Using deferred policy tend to be faster. For async policy, -O3 level has better performance.



### B) Plots for Q2 (5)

The file points.txt is too large, so I display the plot of these points alone

<img src="C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230517165405524.png" alt="image-20230517165405524" style="zoom: 80%;" />



* **Not merged**

  ![image-20230517170923021](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230517170923021.png)

* **After first merge**

  ![image-20230517171107300](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230517171107300.png)

* **After second merge**

  ![image-20230517170714147](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230517170714147.png)

