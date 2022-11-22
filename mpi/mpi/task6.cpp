/*
* ����������� ���������, � ������� ��� �������� ����������� ����������������������� ������ n ����. ��������� ������������ � �������
* ����������� ������� ����������  ��������  ��  �����  ���������.  �����������  ���  ��������  ������ �����������
* 
* a.PingPong - ��������������� ��������. ����������� �������� ������ ��  ��������������  �������  �  �����������  ��������� ����������  
*   ������  � ��������  �������. ����� ���������� ���������� ����� ��������� ��������� ������ �� �������� ��������.
* 
* b.PingPing  - ���������������� ��������.  ���  ��������  ������������  ����������������� ������ ���� �����. 
*   ����� ���������� ���������� ����� ��������� ��������� ������ ���������.
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