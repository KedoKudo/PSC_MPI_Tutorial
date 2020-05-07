#include <mpi.h> 
#include <math.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    const double PI=3.14159265358979323846264338327950288;
    
    int n_intervals, n_pe, idx_pe;
    double pi, pi_pe, x, dx, x_start, x_end, width;

    // MPI init
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &n_pe);
    MPI_Comm_rank(MPI_COMM_WORLD, &idx_pe);

    // getting input
    if( idx_pe == 0 ){ 
        printf("How many intervals? ");
        scanf("%d", &n_intervals);  // cannot convert scientific notation to int, must spell out
    }
    // borad cast it to all pe
    MPI_Bcast(&n_intervals, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Per PE init 
    pi_pe = 0;
    dx = (double) 1/n_intervals;  // must force cast to float
    width = dx/n_pe;
    x_start = idx_pe*width;

    // per pe process
    printf("PE %d start with x_start=%f, dx=%f, width=%f)\n", idx_pe, x_start, dx, width);
    for (x = x_start; x <= 1; x = x+dx){
        pi_pe = pi_pe + width*sqrt(1-x*x);
    }

    // MPI reduce with broadcasting
    MPI_Reduce(&pi_pe, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    pi = pi*4;

    // finalize and report
    if (idx_pe == 0){
        printf("PI is approximated to %f\n", pi);
        printf("Error is %f\n", pi-PI);
    }

    // cleanup
    MPI_Finalize();
}