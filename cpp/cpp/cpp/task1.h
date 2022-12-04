#pragma once
template <class T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T max(T& a, T& b) {
    return (b < a ? a : b);
}

template <class T>
T min(T& a, T& b) {
    return (b > a ? a : b);
}

