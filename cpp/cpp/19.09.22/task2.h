#pragma once
#include <cmath>

class Matrix1d {
public:
	double m[1][1];
	const int size = 1;
	Matrix1d(double m11) {
		m[0][0] = m11;
	}
};

class Matrix2d {
public:
	double m[2][2];
	const int size = 2;
	Matrix2d(double m11, double m12, double m21, double m22) {
		m[0][0] = m11;
		m[0][1] = m12;
		m[1][0] = m21;
		m[1][1] = m22;
	}
};

class Matrix3d {
public:
	double m[3][3];
	const int size = 3;
	Matrix3d(double m11, double m12, double m13, 
		double m21, double m22, double m23, 
		double m31, double m32, double m33) {
		m[0][0] = m11;
		m[0][1] = m12;
		m[0][2] = m13;

		m[1][0] = m21;
		m[1][1] = m22;
		m[1][2] = m23;

		m[2][0] = m31;
		m[1][1] = m32;
		m[2][2] = m33;
	}
};

template <class T>
double norm(T t)
{
	double norm_value = 0;
	for (int i = 0;i < t.size;i++)
		for (int j = 0;j < t.size;j++)
			norm_value += t.m[i][i] * t.m[i][i];

	norm_value = sqrt(norm_value);
	std::cout << "norm(T t) = " << norm_value << std::endl;
	return norm_value;
}

template <class T>
double norm(T *t)
{
	double norm_value = 0;
	for (int i = 0;i < t->size;i++)
		for (int j = 0;j < t->size;j++)
			norm_value += t->m[i][i] * t->m[i][i];

	norm_value = sqrt(norm_value);
	std::cout << "norm(T *t) = " << norm_value << std::endl;
	return norm_value;
}

template<>
double norm<Matrix1d>(Matrix1d* t)
{
	double norm_value = 0;
	for (int i = 0;i < t->size;i++)
		for (int j = 0;j < t->size;j++)
			norm_value += t->m[i][i] * t->m[i][i];

	norm_value = sqrt(norm_value);
	std::cout << "norm(T *t) = " << norm_value << std::endl;
	return norm_value;
}

template<>
double norm<Matrix2d>(Matrix2d* t) 
{
	double norm_value = 0;
	for (int i = 0;i < t->size;i++)
		for (int j = 0;j < t->size;j++)
			norm_value += t->m[i][i] * t->m[i][i];

	norm_value = sqrt(norm_value);
	std::cout << "norm(T *t) = " << norm_value << std::endl;
	return norm_value;
}

template<>
double norm<Matrix3d>(Matrix3d* t)
{
	double norm_value = 0;
	for (int i = 0;i < t->size;i++)
		for (int j = 0;j < t->size;j++)
			norm_value += t->m[i][i] * t->m[i][i];

	norm_value = sqrt(norm_value);
	std::cout << "norm(T *t) = " << norm_value << std::endl;
	return norm_value;
}