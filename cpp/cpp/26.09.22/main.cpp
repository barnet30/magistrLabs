#include <iostream>
#include "Templates.h"


int main()
{
	std::cout << ::sum(2.3, 5.1) << std::endl;
	std::cout << ::sum(200, 102) << std::endl;

	int** matr1 = new int* [5];
	int** matr2 = new int* [5];

	for (int i = 0; i < 5; i++) {
		matr1[i] = new int[5];
		matr2[i] = new int[5];

		for (int j = 0; j < 5; j++) {
			matr1[i][j] = rand() % 10 + 1;
			matr2[i][j] = rand() % 10 + 1;
		}
	}

	Matrix m1(matr1, 5);
	Matrix m2(matr2, 5);

	for (int i = 0; i < 5;i++)
	{
		delete[] matr1[i];
		delete[] matr2[i];
	}
	delete[] matr1;
	delete[] matr2;

	std::cout << std::endl << m1 << std::endl;
	std::cout << m2 << std::endl;

	std::cout << ::sum(m1, m2) << std::endl;

	int a = 101;
	int b = 202;
	int* ptr_a = &a;
	int* ptr_b = &b;

	std::cout << ::sum(ptr_a, ptr_b) << std::endl;

	char const str1[] = "first char string";
	char const str2[] = " second char string";

	std::cout << ::sum(str1, str2) << std::endl;

	std::string string1 = "first std string";
	std::string string2 = " second std string";
	std::cout << ::sum(string1, string2) << std::endl;

	return EXIT_SUCCESS;
}
