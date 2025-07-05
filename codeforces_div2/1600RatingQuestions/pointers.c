#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

#include"mpi.h"
int count = 100;
int main(int argc , char *argv[]){
    char mssg[20] , recvmssg[100];
    int rank , size;
    MPI_Status status;
    MPI_Init(&argc , &argv);
    MPI_Comm_rank(MPI_COMM_WORLD , &rank);
    if(rank == 0){
        strcpy(mssg , "Hello World 1");
        MPI_Send(mssg , strlen(mssg) + 1 , MPI_CHAR , 1 , 99 , MPI_COMM_WORLD);
    }else{
        MPI_Recv(recvmssg , 100 , MPI_CHAR , 0 , 99 , MPI_COMM_WORLD , &status);
        printf("Received message is %s\n" , recvmssg);
    }
    MPI_Finalize();
}
// 