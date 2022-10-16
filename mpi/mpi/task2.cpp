#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"
#include <ctime>


// mpiexec -n 2 mpi.exe

int main2()
{
    const int N = 10;
    MPI_Status status;

    int ProcNum;
    int rank;
    srand(time(0));
    int a[N];


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("%i rank create array a\n", rank);
        srand(time(0));
        for (int i = 0;i < N;i++)
            a[i] = rand() % 100 + 1;
        MPI_Send(a, N, MPI_INT, 1, 0, (MPI_Comm)MPI_COMM_WORLD);
    }
    else 
    {
        MPI_Recv(a, N, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        printf("%i process show us array a:\n", rank);
        for (int i = 0;i < N;i++)
            printf("%i ", a[i]);
    }



    MPI_Finalize();

    return EXIT_SUCCESS;
}