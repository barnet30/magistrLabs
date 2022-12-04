#include<iostream>
#include "task1.h"
#include "task2.h"
using namespace std;

int main() {
	int a = 10;
	int b = 5;

	::swap(a, b);
	
	cout << "a = " << a << ", b = " << b << endl;
	cout << "max(a, b) = " << ::max(a, b) << endl;
	cout << "min(a, b) = " << ::min(a, b) << endl;


	string c = "str1";
	string d = "str2";

	::swap(c, d);
	cout << "c = " << c << ", d = " << d << endl;
	cout << "max(c, d) = " << ::max(c, d) << endl;
	cout << "min(c, d) = " << ::min(c, d) << endl;

	// task2 
	cout << endl << "TASK 2" << endl;
	int* arr = new int[5] {1, 2, 3, 4, 5};
	void (*func) (int el);
	func = showSquare<int>;
	iter(arr, 5, func);
}