#pragma once
#include <complex>

const double eps = 1e-15;

template <class T>
class Equation {
    T a, b, c;
public:
    Equation(T a1, T b1, T c1);
    void solve();
};

double doubleExp(const double x) {
    double exp, temp;
    int n = 1;
    for (exp = 1.0, temp = 1.0; temp >= eps; ++n) {
        temp *= (double)x / n;
        exp += temp;
    }
    return exp;
}

double doubleSqrt(const double d) {
    const double sqrtBase = 1.0 / 2.0;
    return doubleExp(sqrtBase * log(d));
}

template <typename T> 
std::complex<T> complexSqrt(const std::complex<T>& z) {
    double x = z.real() * z.real() + z.imag() * z.imag();
    const double c_module = doubleSqrt(x);
    const double fi = std::atan(z.imag() / z.real());
    return std::complex(c_module * std::cos(fi), c_module * std::sin(fi));
}

template <class T>
Equation<T>::Equation(T a1, T b1, T c1) :a(a1), b(b1), c(c1) {};

template <class T>
void Equation<T>::solve() {
    if (a == 0 && b == 0 && c == 0) {
        std::cout << "Бесконечное число корней" << std::endl;
        return;
    }
    else if (a == 0 && b == 0 && c != 0) {
        std::cout << "Корней нет" << std::endl;
        return;
    }
    else if (a == 0 && b != 0) {
        std::cout << "Один корень x = " << (- c) / b << std::endl;
        return;
    }
    else if (a != 0 && b != 0 && c == 0) {
        std::cout << "x1 = " << 0 << std::endl;
        std::cout << "x2 = " << -b / a << std::endl;
        return;
    }
    
    T D = b * b - 4 * a * c;
    if (D == 0) {
        std::cout << "x1 = x2 = " << -b / (2 * a) << std::endl;
        return;
    }
    else if (D < 0) {
        double d = doubleSqrt(-D);
        std::cout << "x1 = " << -b / (2 * a) << " + i" << d / (2 * a) << std::endl;
        std::cout << "x2 = " << -b / (2 * a) << " - i" << d / (2 * a) << std::endl;
        return;
    }
    else if (D > 0) {
        double d = doubleSqrt(D);
        std::cout << "x1 = " << (-b + d) / (2 * a) << std::endl;
        std::cout << "x2 = " << (-b - d) / (2 * a) << std::endl;
        return;
    }
    return;
}
