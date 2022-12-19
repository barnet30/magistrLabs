#pragma once
#include <cmath>

class Complex {
public:
	double re, im;
};

class Matrix {
public:
	double A[2][2];
	Matrix(double a11, double a12, double a21, double a22) {
		A[0][0] = a11;
		A[0][1] = a12;
		A[1][0] = a21;
		A[1][1] = a22;
	}
};

class Real {
public:
	double number;
};

template <class T>
double modul(T el) {
	return abs(el.number);
}

template <>
double modul<Matrix>(Matrix el) {
	return (el.A[0][0] * el.A[1][1] - el.A[0][1] * el.A[1][0]);
}

template <>
double modul<Complex>(Complex el) {
	return sqrt(el.re * el.re + el.im * el.im);
}