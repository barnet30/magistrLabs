#pragma once
#include <iostream>

class Complex {
public:
	Complex();
	Complex(double Re, double Im);
	Complex(Complex const& c);
	Complex& operator=(Complex const& c);
	double operator[](size_t i) const;
	Complex operator+(Complex const& c) const;
	friend std::ostream& operator<<(std::ostream& out, Complex const& c); 

private:
	double re, im;
};