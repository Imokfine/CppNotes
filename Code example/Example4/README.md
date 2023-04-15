## Results

### Random Walk

When 10x10 grid, **k=0.0**, 100 steps

![image](https://user-images.githubusercontent.com/98553439/232237049-d72537f0-a7fd-48a5-ae1d-617fcdd10683.png)




When 10x10 grid, **k=0.1**, 100 steps

![image](https://user-images.githubusercontent.com/98553439/232237056-cca7c53c-fde8-4376-a811-9c3916f80a32.png)



When 10x10 grid, **k=0.5**, 100 steps

![image](https://user-images.githubusercontent.com/98553439/232237066-7dddc326-8e55-4ad2-989b-019179dab5d6.png)



When 10x10 grid, **k=1.0**, 100 steps

![image](https://user-images.githubusercontent.com/98553439/232237072-5bde5d5a-b90d-4830-b2b5-b11252a6938d.png)



### Monte Carlo Simulation for Social distancing

**When k=0.0**, 100x100 grid, 10,000 population & 200x200 grid, 10,000 population

![image](https://user-images.githubusercontent.com/98553439/232237231-510a585c-366c-454a-a2d9-479d6a5d4cd7.png)


**When k=0.5**, 100x100 grid, 10,000 population & 100x100 grid, 20,000 population

![image](https://user-images.githubusercontent.com/98553439/232237254-466bf765-19ba-485f-8b00-70a2fc92a39d.png)


**When k=1.0**, 100x100 grid, 10,000 population & 100x100 grid, 20,000 population

![image](https://user-images.githubusercontent.com/98553439/232237274-6f2710ae-fc8f-4b42-9719-297abd4f057d.png)



## README

To make the plots, access gnuplot firstly

```bash
gnuplot
```



### Random Walk

For **10x10 grid, k=0.0, 100 steps**, run

```bash
load "plota1.gp"
```

For **10x10 grid, k=0.1, 100 steps**, run

```bash
load "plota2.gp"
```

For **10x10 grid, k=0.5, 100 steps**, run

```bash
load "plota3.gp"
```

For **10x10 grid, k=1.0, 100 steps**, run

```bash
load "plota4.gp"
```



### Monte Carlo Simulation for Social distancing

**When k=0.0**

100x100 grid, 10,000 population

```bash
load "plotb1.gp"
```

200x200 grid, 10,000 population

```bash
load "plotb4.gp"
```

**When k=0.5**

100x100 grid, 10,000 population

```bash
load "plotb2.gp"
```

100x100 grid, 20,000 population

```bash
load "plotb5.gp"
```

**When k=1.0**

100x100 grid, 10,000 population

```bash
load "plotb3.gp"
```

100x100 grid, 20,000 population

```bash
load "plotb6.gp"
```






