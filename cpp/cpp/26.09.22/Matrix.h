#pragma once
#include <iostream>

class Matrix {
public:
	Matrix();
	Matrix(int sizeIn);
	Matrix(int** m, int sizeIn);
	Matrix(Matrix const& m);
	~Matrix();
	Matrix& operator=(Matrix const& m);
	Matrix operator+(Matrix const& m) const;
	friend std::ostream& operator<<(std::ostream& out, Matrix const& m);
private:
	int** a;
	int size;
};
