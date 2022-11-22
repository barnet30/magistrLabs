#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"
#include <ctime>
#include <vector>
#include <array>
#include <memory>
#include <iostream>


// mpiexec -n 4 mpi.exe

int main4()
{
    const int N = 10;
    const int GENERAL_PROCESS = 0;
    const int FIRST_PROCESS = 1;
    const bool calcSum = true;
    const bool calcMult = false;

    int ProcNum;
    int rank;
    srand(time(0));
    std::array<int,N> x;
    std::array<int,N> y;
    std::array<int,N> z;


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (ProcNum < 2)
    {
        std::cout << "Number of processes is not enough";
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
        return EXIT_FAILURE;

    }

    if (rank == GENERAL_PROCESS)
    {
        MPI_Status status;

        printf("%i proccess create arrays x and y\n", rank);
        srand(time(0));

        for (int i = 0;i < N;i++)
        {
            x[i] = rand() % 100 + 1;
            y[i] = rand() % 100 + 1;
        }

        // ProcNum - 1, cause of 0 proccess doesn't participate in calculations
        std::vector < std::pair<int, std::pair<int, int>>> batches(ProcNum - 1, std::make_pair(0, std::make_pair(0, 0)));
        for (int i = 0; i < ProcNum-1; i++)
        {
            int procToSend = i+1;
            int batch = (int)round((double)N / (ProcNum - 1));
            if (N % ProcNum != 0 && procToSend == (ProcNum - 1))
            {
                batch = N - (procToSend - 1) * batch;
            }
            int beginIdx = i * batch;
            if (procToSend == (ProcNum - 1))
                beginIdx = batches[i - 1].second.second + 1;

            batches[i].first = procToSend;
            batches[i].second.first = beginIdx;
            batches[i].second.second = beginIdx + batch - 1;
            //beginIdx = beginIdx * i + batch;
            //std::cout << batches[i].first << " " << batches[i].second.first << " " << batches[i].second.second << " " << batch << std::endl;
        }

        for (int i = 0; i < ProcNum - 1; i++)
        {
            int beginIdx = batches[i].second.first;
            int endIdx = batches[i].second.second;
            int batchSize = endIdx - beginIdx + 1;
            //int offset = i * batchSize;
            int procToSend = batches[i].first;

            std::vector<int> xToSend(batchSize);
            std::vector<int> yToSend(batchSize);

            for (int j = beginIdx, k = 0; j <= endIdx && k < batchSize;j++, k++)
            {
                xToSend[k] = x[j];
                yToSend[k] = y[j];
            }


            MPI_Send(xToSend.data(), batchSize, MPI_INT, procToSend, 1, MPI_COMM_WORLD);
            MPI_Send(yToSend.data(), batchSize, MPI_INT, procToSend, 0, MPI_COMM_WORLD);
        }


        for (int i = 0; i < ProcNum - 1; i++)
        {
            int beginIdx = batches[i].second.first;
            int endIdx = batches[i].second.second;
            int batchSize = endIdx - beginIdx + 1;
            int offset = i * batchSize;
            int procFromRecv = batches[i].first;

            std::cout << procFromRecv << " " << batchSize << " " << beginIdx << std::endl;
            MPI_Recv(z.data() + beginIdx, batchSize, MPI_INT, procFromRecv, MPI_ANY_TAG, MPI_COMM_WORLD, &status); 
            for (int j = beginIdx; j <= endIdx; j++) {
                printf("z[%u]=%u : x[%u]=%u : y[%u]=%u\n", j, z[j], j, x[j], j, y[j]);
            }
        }

       
        
    }
    else
    {
        MPI_Status status;
        int count; 
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);

        std::vector<int> bufferX(count);
        std::vector<int> bufferY(count);
        std::vector<int> resultBatch(count);

        MPI_Recv(bufferX.data(), count, MPI_INT, status.MPI_SOURCE, 1, (MPI_Comm)MPI_COMM_WORLD, &status);
        MPI_Recv(bufferY.data(), count, MPI_INT, status.MPI_SOURCE, 0, (MPI_Comm)MPI_COMM_WORLD, &status);

        if (calcSum)
            for (int i = 0; i < count;i++)
            {
                resultBatch[i] = bufferX[i] + bufferY[i];
            }

        if (calcMult)
            for (int i = 0; i < count;i++)
            {
                resultBatch[i] = bufferX[i] * bufferY[i];
            }

        MPI_Send(resultBatch.data(), count, MPI_INT, GENERAL_PROCESS, 0, MPI_COMM_WORLD);

    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}