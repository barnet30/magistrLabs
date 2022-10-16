#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"

// mpiexec -n 4 mpi.exe

int main()
{
	MPI_Status status;

    int ProcNum;
    int ProcRank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);

    printf("Rank of process %i from %i processes  \n", ProcRank, ProcNum);

    MPI_Finalize();

    return EXIT_SUCCESS;
}