#include "Complex.h"

Complex::Complex() :re(0), im(0) { }

Complex::Complex(double Re, double Im) :re(Re), im(Im) { }

Complex::Complex(Complex const& c) :re(c.re), im(c.im) { }

Complex& Complex::operator=(Complex const& c) {
	if (this != &c) {
		re = c.re;
		im = c.im;
	}
	return *this;
}

double Complex::operator[](size_t i) const {
	return i == 0 ? re : im;
}

Complex Complex::operator+(Complex const& c) const {
	return Complex(re + c.re, im + c.im);
}

std::ostream& operator<<(std::ostream& out, Complex const& c) {
	if (c.im < 0)
		out << c.re << c.im << "i";
	else
		out << c.re << "+" << c.im << "i";
	return out;
}
