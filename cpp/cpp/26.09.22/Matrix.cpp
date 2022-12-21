#include "Matrix.h"

Matrix::Matrix() {
	size = 1;
	a = new int* [1];
	for (size_t i = 0; i < 1; i++) {
		a[i] = new int[1];
		for (size_t j = 0; j < 1; j++)
			a[i][j] = 0;
	}
}

Matrix::Matrix(int sizeIn) {
	size = sizeIn;
	a = new int* [size];
	for (size_t i = 0; i < size; i++) {
		a[i] = new int[size];
		for (size_t j = 0; j < size; j++)
			a[i][j] = 0;
	}
}


Matrix::Matrix(int** m, int sizeIn) {
	this->size = sizeIn;
	this->a = new int* [size];
	for (size_t i = 0; i < size; i++) {
		this->a[i] = new int[size];
		for (size_t j = 0; j < size; j++)
			this->a[i][j] = m[i][j];
	}
}

Matrix::Matrix(Matrix const& m) : size(m.size) {
	a = new int* [size];
	for (size_t i = 0; i < m.size; ++i)
	{
		a[i] = new int[size];
		for (size_t j = 0; j < m.size; j++)
			a[i][j] = m.a[i][j];
	}
}

Matrix::~Matrix() {
	for (size_t i = 0; i < size; i++)
		delete[] a[i];
	delete[] a;
}

Matrix& Matrix::operator=(Matrix const& m) {
	if (this != &m) {
		for (size_t i = 0; i < m.size; i++)
			delete[] a[i];
		delete[] a;

		a = new int* [m.size];
		for (size_t i = 0; i < m.size; ++i) {
			a[i] = new int[m.size];
			for (size_t j = 0; j < m.size; j++)
				a[i][j] = m.a[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(Matrix const& m) const {
	Matrix res(m.size);
	for (size_t i = 0; i < m.size; ++i) {
		for (size_t j = 0; j < m.size; j++)
			res.a[i][j] = a[i][j] + m.a[i][j];
	}
	return res;
}

std::ostream& operator<<(std::ostream& out, Matrix const& m) {
	for (size_t i = 0; i < m.size; i++) {
		for (size_t j = 0; j < m.size; j++)
			out << m.a[i][j] << ' ';
		out << '\n';
	}
	return out;
}