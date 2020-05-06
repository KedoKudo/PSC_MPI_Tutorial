# Problem statement

The area of a circle of radius of 1 is equaled to PI.
Therefore, we can numericallly calculate the value of PI by integrating the area.
Here we are going to use MPI to carry out calculations so that multiple nodes calucating a subset of the circle, which is then reduced/summed to the total.
The final results should be printed to the terminal once all data processing is done.