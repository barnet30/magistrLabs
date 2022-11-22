/*
* Разработать программу, в которой два процесса многократно обмениваютсясообщениями длиной n байт. Выполнить эксперименты и оценить
* зависимость времени выполнения  операции  от  длины  сообщения.  Рассмотреть  два  варианта  обмена сообщениями
* 
* a.PingPong - двунаправленная передача. Выполняется передача данных от  одногопроцесса  другому  с  последующим  возвратом переданных  
*   данных  в исходный  процесс. Время выполнение замеряется после получения обратного ответа на исходном процессе.
* 
* b.PingPing  - однонаправленная передача.  Два  процесса  одновременно  выполняютпередачу данных друг другу. 
*   Время выполнение замеряется после получения сообщения каждым процессом.
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

int main6()
{
    int ProcNum;
    int ProcRank;
    srand(time(0));


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);

    if (ProcNum != 3) {
        cerr << "Incorrect processors! Need 3! Current: " << ProcNum << endl;
        MPI_Finalize();
        return EXIT_FAILURE;
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}