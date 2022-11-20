#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"
#include <ctime>


// mpiexec -n 2 mpi.exe

int main3()
{
    const int N = 10;
    const int GENERAL_PROCESS = 0;
    const int FIRST_PROCESS = 1;
    MPI_Status status;

    int ProcNum;
    int rank;
    srand(time(0));
    int a[N];


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == FIRST_PROCESS)
    {
        printf("%i rank create array a\n", rank);
        srand(time(0));
        for (int i = 0;i < N;i++)
            a[i] = rand() % 100 + 1;

        for (int i = 0; i < ProcNum; i++) {
            if (i == FIRST_PROCESS)
                continue;
            MPI_Send(a, N, MPI_INT, i, 0, (MPI_Comm)MPI_COMM_WORLD);
        }
    }
    else
    {
        int count;
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);

        int* buff_array = new int[count];
        MPI_Recv(buff_array, count, MPI_INT, status.MPI_SOURCE, status.MPI_TAG, MPI_COMM_WORLD, &status);
        printf("%i process show us received batch of array a:\n", rank);
        for (int i = 0;i < count;i++)
            printf("%i ", buff_array[i]);
        printf("\n");
        delete[] buff_array;
    }



    MPI_Finalize();

    return EXIT_SUCCESS;
}