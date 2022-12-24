#pragma once

template <unsigned N>
struct Factorial {
	static const unsigned value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
	static const unsigned value = 1;
};

template<unsigned alpha, unsigned beta>
struct monomial_2d {
	static const unsigned value =
		Factorial<alpha + beta + 2>::value / (Factorial<alpha>::value * Factorial<beta>::value);
};