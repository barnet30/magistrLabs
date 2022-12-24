#pragma once
template<unsigned index>
struct Fibonacci {
	static constexpr unsigned value = Fibonacci<index - 1>::value + Fibonacci<index - 2>::value;
};

template<>
struct Fibonacci<1> {
    static constexpr unsigned value = 1;
};

template<>
struct Fibonacci<0> {
    static constexpr unsigned value = 0;
};