#pragma once
template <class t1, class t2, class t3>
void iter(t1* m, t2 l, t3(*f)(t1 o)) {
    for (int i = 0; i < l; i++)
        (*f)(m[i]);
    std::cout << std::endl;
};

template <class t1>
void showSquare(t1 el) {
    std::cout << el * el << std::endl;
};