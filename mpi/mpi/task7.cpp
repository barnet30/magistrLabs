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

int calcNorm(int* arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += abs(arr[i]);
    }
    return result;
}

int main7()
{
    const int N = 10;
    const int GENERAL_PROCESS = 0;

    int ProcNum;
    int ProcRank;
    srand(time(0));


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);

    int* sourceArray = new int[N];
    int result = 0;
    
    if (ProcRank == GENERAL_PROCESS) {
        printf("\nCurrent Array:\n");
        for (int i = 0;i < N;i++)
        {
            sourceArray[i] = rand() % 100 + 1;
            printf("%u ", sourceArray[i]);
        }
        printf("\n");
    }

    if (N % (ProcNum - 1) != 0 && ProcRank == ProcNum - 1)
    {
        int batch = (int)round((double)N / (ProcNum - 1));
        int lastProcBatch = N - (ProcNum - 1) * batch;

        int* chunk = new int[lastProcBatch];
        MPI_Scatter(
            sourceArray, lastProcBatch, MPI_INT,
            chunk, lastProcBatch, MPI_INT,
            0, MPI_COMM_WORLD);

        printf("\nCurrent chunk:\n");
        for (int i = 0;i < lastProcBatch;i++)
        {
            sourceArray[i] = rand() % 100 + 1;
            printf("%u ", chunk[i]);
        }

        printf("\n");      
        int chunkResult = calcNorm(chunk, lastProcBatch);
        printf("\nChunk result from %u proc: %u", ProcRank, chunkResult);
        MPI_Reduce(&chunkResult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        delete[] chunk;
    }
    else 
    {
        int batch = (int)round((double)N / (ProcNum - 1));

        int* chunk = new int[batch];
        MPI_Scatter(
            sourceArray, batch, MPI_INT,
            chunk, batch, MPI_INT,
            0, MPI_COMM_WORLD);

        printf("\nCurrent chunk:\n");
        for (int i = 0;i < batch;i++)
        {
            sourceArray[i] = rand() % 100 + 1;
            printf("%u ", chunk[i]);
        }

        int chunkResult = calcNorm(chunk, batch);
        printf("\nChunk result from %u proc: %u", ProcRank, chunkResult);
        MPI_Reduce(&chunkResult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        delete[] chunk;
    }

    if (ProcRank == GENERAL_PROCESS) {
        printf("\n Get result from %u proc: %u", ProcRank, result);
    }

    MPI_Finalize();
    delete[] sourceArray;

    return EXIT_SUCCESS;
}