# Compute PI

## Problem statement

The area of a circle of radius of 1 is equaled to PI.
Therefore, we can numericallly calculate the value of PI by integrating the area.
Here we are going to use MPI to carry out calculations so that multiple nodes calucating a subset of the circle, which is then reduced/summed to the total.
The final results should be printed to the terminal once all data processing is done.

## Usage

Compile with any MPI compiler

```bash
>> mpicc -O3 ex1_calcPi.c
```

and here are the sample output.

```bash
❯ mpirun -n 4 ./a.out
How many intervals? 100
PE 0 start with x_start=0.000000, dx=0.010000, width=0.002500)
PE 1 start with x_start=0.002500, dx=0.010000, width=0.002500)
PE 2 start with x_start=0.005000, dx=0.010000, width=0.002500)
PE 3 start with x_start=0.007500, dx=0.010000, width=0.002500)
PI is approximated to 3.146458
Error is 0.004866
❯ mpirun -n 4 ./a.out
How many intervals? 1000
PE 0 start with x_start=0.000000, dx=0.001000, width=0.000250)
PE 1 start with x_start=0.000250, dx=0.001000, width=0.000250)
PE 2 start with x_start=0.000500, dx=0.001000, width=0.000250)
PE 3 start with x_start=0.000750, dx=0.001000, width=0.000250)
PI is approximated to 3.142119
Error is 0.000527
❯ mpirun -n 4 ./a.out
How many intervals? 10000
PE 0 start with x_start=0.000000, dx=0.000100, width=0.000025)
PE 1 start with x_start=0.000025, dx=0.000100, width=0.000025)
PE 2 start with x_start=0.000050, dx=0.000100, width=0.000025)
PE 3 start with x_start=0.000075, dx=0.000100, width=0.000025)
PI is approximated to 3.141545
Error is -0.000047
```

## Afterthoughts

Writing MPI code is very similar to writing a serial processing code.
However, the majority of the focus is often placed on partitioning the worklaod (for example, the domain decomposition in example 2).
This often means that the MPI code is not designed to run as a single processor, and the same code cannot be easily toggled bewteen MPI mode and single node mode.
However, most of the modern machine has multiple cores, which can serve as multiple PE (processing element).
Therefore, we can always run the MPI code with mpirun on a pre-configured machine.
