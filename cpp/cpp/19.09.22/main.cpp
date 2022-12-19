#include <iostream>
#include "task1.h"
#include "task2.h"

using std::cout;
using std::endl;

int main()
{
    std::cout << "TASK 1\n";
    Real realNumber = { -10 };
    Complex c1 = { 3,-2 };
    Matrix A(5, 2, 1, 6);

    cout << "module Real = " << modul(realNumber) << endl;
    cout << "module Complex = " << modul(c1) << endl;
    cout << "module Matrix = " << modul(A) << endl;

    std::cout << "\nTASK 2\n";

    Matrix1d m1(1);
    Matrix2d m2(1, 2, 3, 4);
    Matrix3d m3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    norm(m1);
    norm(m2);
    norm(m3);
    norm(&m1);
    norm(&m2);
    norm(&m3);
}
