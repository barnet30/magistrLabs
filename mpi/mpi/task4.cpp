#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"
#include <ctime>
#include <vector>


// mpiexec -n 2 mpi.exe

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
    std::vector<int> x(N);
    std::vector<int> y(N);
    std::vector<int> z(N);


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == GENERAL_PROCESS)
    {
        MPI_Status status;

        printf("%i proccess create array a\n", rank);
        srand(time(0));

        for (int i = 0;i < N;i++)
        {
            x[i] = rand() % 100 + 1;
            y[i] = rand() % 100 + 1;
        }

        // ProcNum - 1, cause of 0 proccess doesn't partiipate in calculations
        std::vector<std::pair<int, int>> batches(ProcNum - 1, std::make_pair(0, 0));
        for (int i = 1; i < ProcNum; i++)
        {
            int batch = (int)round((double)N / ProcNum - 1);
            if (N % ProcNum != 0 && i == ProcNum - 1)
            {
                batch = N - (ProcNum - 1) * batch;
            }

            batches[i - 1].first = i;
            batches[i - 1].second = batch;
        }

        for (int i = 0; i < ProcNum - 2; i++)
        {
            int batchSize = batches[i].second;
            int offset = i * batchSize;
            int procToSend = batches[i].first;

            MPI_Send(x.data() + offset, batchSize, MPI_INT, procToSend, 0, MPI_COMM_WORLD);
            MPI_Send(y.data() + offset, batchSize, MPI_INT, procToSend, 1, MPI_COMM_WORLD);
        }

        for (int i = 1; i < ProcNum; i++)
        {
            int batchSize = batches[i].second;
            int offset = i * batchSize;
            int procFromRecv = batches[i].first;

            MPI_Recv(z.data() + offset, batchSize, MPI_INT, procFromRecv, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        }

        for (int i = 0; i < z.size(); i++) {
            printf("z[%u]=%u : x[%u]=%u : y[%u]=%u\n", i, z[i], i, x[i], i, y[i]);
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

        MPI_Recv(bufferX.data(), (int)count, MPI_INT, status.MPI_SOURCE, 0, (MPI_Comm)MPI_COMM_WORLD, &status);
        MPI_Recv(bufferY.data(), (int)count, MPI_INT, status.MPI_SOURCE, 1, (MPI_Comm)MPI_COMM_WORLD, &status);

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