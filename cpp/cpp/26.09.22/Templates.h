#pragma once

#include "Complex.h"
#include "Matrix.h"
#include <cstring>
#include <string>


template<typename T>
T sum(T a, T b) {
	std::cout << "sum for real called\n";
	return a + b;
}

template<>
Complex sum(Complex a, Complex b) {
	std::cout << "sum for complex numbers called\n";
	return a + b;
}

template<>
Matrix sum(Matrix a, Matrix b) {
	std::cout << "sum for matrix called\n";
	return a + b;
}

char* sum(char const* a, char const* b) {
	std::cout << "sum for C-style strings called\n";
	char* tmp = new char[strlen(a) + strlen(b) + 1];
	char* iter_tmp = tmp;
	char const* iter_a = a;
	while (*iter_a)
		*iter_tmp++ = *iter_a++;
	char const* iter_b = b;
	while (*iter_b)
		*iter_tmp++ = *iter_b++;
	*iter_tmp = '\0';

	return tmp;
}

std::string sum(std::string a, std::string b) {
	std::cout << "sum for string types called\n";
	return a + b;
}

template<typename T>
T sum(T* a, T* b) {
	std::cout << "sum for pointers called\n";
	return *a + *b;
}