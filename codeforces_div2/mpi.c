#include<stdio.h>
#include<stdint.h>
#include"mpi.h"
int main(){
    int size , rank;
    MPI_Init(NULL, NULL);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
int data;
if (rank == 0) {
data = 100;
}
MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
printf("Rank %d received %d\n", rank, data);
MPI_Finalize();
}