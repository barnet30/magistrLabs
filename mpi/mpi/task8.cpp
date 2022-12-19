/*
* Написать  программу  вычисления  нормы ‖𝑥‖1=∑ |𝑥𝑖|𝑛−1𝑖=0вектора  x.  Для распределения элементов вектора x по процессам
* использовать функцию MPI_Scatter. Для получения  итоговой  суммы  на  нулевом  процессе  использовать  функцию  MPI_Reduce
* с операцией MPI_Sum.
*/

#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"
#include <ctime>
#include <vector>
#include <array>
#include <memory>
#include <iostream>
using namespace std;

// mpiexec -n 4 mpi.exe

int calcScalar(int* a, int* b, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += a[i] * b[i];
    }
    return result;
}

int main8()
{
    const int N = 10;
    const int GENERAL_PROCESS = 0;

    int ProcNum;
    int ProcRank;
    srand(time(0));

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);

    int* arr1 = new int[N];
    int* arr2 = new int[N];
    int result = 0;

    if (ProcRank == GENERAL_PROCESS) {
        for (int i = 0;i < N;i++)
        {
            arr1[i] = rand() % 100 + 1;
            arr2[i] = rand() % 100 + 1;
        }

        printf("\nShow Arrays:\n");
        printf("\nArray 1:\n");
        for (int i = 0;i < N;i++)
            printf("%u ", arr1[i]);

        printf("\nArray 2:\n");
        for (int i = 0;i < N;i++)
            printf("%u ", arr2[i]);

        printf("\n");
    }

    if (N % (ProcNum - 1) != 0 && ProcRank == ProcNum - 1)
    {
        int batch = (int)round((double)N / (ProcNum - 1));
        int lastProcBatch = N - (ProcNum - 1) * batch;

        int* chunkArr1 = new int[lastProcBatch];
        int* chunkArr2 = new int[lastProcBatch];
        MPI_Scatter(
            arr1, lastProcBatch, MPI_INT,
            chunkArr1, lastProcBatch, MPI_INT,
            0, MPI_COMM_WORLD);

        MPI_Scatter(
            arr2, lastProcBatch, MPI_INT,
            chunkArr2, lastProcBatch, MPI_INT,
            0, MPI_COMM_WORLD);

        printf("\nCurrent chunks:\n");
        printf("Chunkarr 1:\n");
        for (int i = 0;i < lastProcBatch;i++)
        {
            printf("%u ", chunkArr1[i]);
        }

        printf("\nChunkarr 2:\n");
        for (int i = 0;i < lastProcBatch;i++)
        {
            printf("%u ", chunkArr2[i]);
        }

        printf("\n");
        int chunkResult = calcScalar(chunkArr1, chunkArr2, lastProcBatch);
        printf("\nChunk result from %u proc: %u", ProcRank, chunkResult);
        MPI_Reduce(&chunkResult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        delete[] chunkArr1;
        delete[] chunkArr2;
    }
    else
    {
        int batch = (int)round((double)N / (ProcNum - 1));

        int* chunkArr1 = new int[batch];
        int* chunkArr2 = new int[batch];
        MPI_Scatter(
            arr1, batch, MPI_INT,
            chunkArr1, batch, MPI_INT,
            0, MPI_COMM_WORLD);

        MPI_Scatter(
            arr2, batch, MPI_INT,
            chunkArr2, batch, MPI_INT,
            0, MPI_COMM_WORLD);

        printf("\nCurrent chunks:\n");
        printf("Chunkarr 1:\n");
        for (int i = 0;i < batch;i++)
        {
            printf("%u ", chunkArr1[i]);
        }

        printf("\nChunkarr 2:\n");
        for (int i = 0;i < batch;i++)
        {
            printf("%u ", chunkArr2[i]);
        }

        printf("\n");

        int chunkResult = calcScalar(chunkArr1, chunkArr2, batch);
        printf("\nChunk result from %u proc: %u", ProcRank, chunkResult);
        MPI_Reduce(&chunkResult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        delete[] chunkArr1;
        delete[] chunkArr2;
    }

    if (ProcRank == GENERAL_PROCESS) {
        printf("\n Get result from %u proc: %u\n", ProcRank, result);
    }

    MPI_Finalize();
    delete[] arr1;
    delete[] arr2;

    return EXIT_SUCCESS;
}