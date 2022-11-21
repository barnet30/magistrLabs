/*
* Пусть на нулевом процессе задана матрица А и вектор х. Написать программу, вкоторой  матрица  равными  блоками  с  нулевого  процесса  
* пересылается  остальным процессам.  Пересылка  данных  осуществляется  функцией  MPI_Send.  Все  процессы  по формуле  вычисляют  свои  
* элементы  искомых  массивов.  Каждый  процесс  отправляет  на нулевой процесс посчитанные элементы массивов. В программе реализовать операцию 
* x = diag(A)  - выделения главной диагонали.
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

int main5()
{
    const int N = 5;
    int diagonalElement;
    const int GENERAL_PROCESS = 0;
    const int STATUS_OK = 200;
    const int STATUS_END = 202;
    const int STATUS_NOT_FOUND = 404;

    int ProcNum;
    int ProcRank;
    srand(time(0));


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    int statusWork = STATUS_OK;

    if (ProcRank == GENERAL_PROCESS) {

        vector<int> result;
        int** matrix = new int*[N];
        for (int i = 0; i < N;i++)
        {
            matrix[i] = new int[N];
        }

        for (int i = 0; i < N;i++)
        {
            for (int j = 0;j < N;j++)
            {
                matrix[i][j] = rand() % 100 + 1;
                printf("%u ", matrix[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < N && statusWork != STATUS_NOT_FOUND; i += ProcNum - 1) {

            for (int id = 1; id < ProcNum; id++) {

                // break if no rows
                int rowI = i + id - 1;
                if (rowI >= N) {
                    break;
                }

                // send status
                statusWork = STATUS_OK;
                MPI_Send(&statusWork, 1, MPI_INT, id, 1, MPI_COMM_WORLD);

                // send row & index of row 
                MPI_Send(matrix[rowI], N, MPI_INT, id, 0, MPI_COMM_WORLD);
                MPI_Send(&rowI, 1, MPI_INT, id, 0, MPI_COMM_WORLD);
            }

            // receiving results of all proc
            for (int id = 1; id < ProcNum; id++) {

                // break if no procs
                int rowI = i + id - 1;
                if (rowI >= N) {
                    break;
                }

                MPI_Recv(&statusWork, 1, MPI_INT, id, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                if (statusWork == STATUS_NOT_FOUND)
                    break;

                // recv diagonal item
                MPI_Recv(&diagonalElement, 1, MPI_INT, id, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                result.push_back(diagonalElement);
            }
        }  

        statusWork = STATUS_END;
        for (int id = 1; id < ProcNum; id++) {
            MPI_Send(&statusWork, 1, MPI_INT, id, 1, MPI_COMM_WORLD);
        };

        printf("\nResult:\n");
        for (int i = 0; i < N;i++)
            printf("%u ", result[i]);

        for (int i = 0; i < N;i++)
            delete[] matrix[i];
        delete[] matrix;
    }
    else
    {
        int row[N];
        int rowI;
        int statusWork;

        while (true) {


            MPI_Recv(&statusWork, 1, MPI_INT, GENERAL_PROCESS, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            if (statusWork == STATUS_END) {
                break;
            }

            // recv row
            MPI_Recv(row, N, MPI_INT, GENERAL_PROCESS, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            // recv index of row
            MPI_Recv(&rowI, 1, MPI_INT, GENERAL_PROCESS, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            printf("Get %u row\n", rowI);
            for (int i = 0; i < N;i++)
                printf("%u ", row[i]);

            printf("\n");

            diagonalElement = row[rowI];
            statusWork = STATUS_OK;
            MPI_Send(&statusWork, 1, MPI_INT, GENERAL_PROCESS, 1, MPI_COMM_WORLD);
            MPI_Send(&diagonalElement, 1, MPI_INT, GENERAL_PROCESS, 0, MPI_COMM_WORLD);

            printf("Diagonal element: %d\n", diagonalElement);

            if (rowI == N) {
                statusWork = STATUS_NOT_FOUND;
                MPI_Send(&statusWork, 1, MPI_INT, GENERAL_PROCESS, 1, MPI_COMM_WORLD);
                break;
            }               
        }
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}