#include <iostream>
#include "Fibonacci.h"
#include "Integral.h"

using namespace std;
int main()
{
    cout << "TASK 1\n";
    cout << Fibonacci<7>::value << endl;

    cout << "\nTASK 2\n";
    cout << "monomial_2d = " << monomial_2d<2, 2>::value << endl;
    cout << "monomial_2d = " << monomial_2d<4, 4>::value;

    return EXIT_SUCCESS;
}
