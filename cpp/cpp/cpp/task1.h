#pragma once
template <class t1>
void swap(t1& a, t1& b) {
    t1 temp = a;
    a = b;
    b = temp;
}

template <class t1>
t1 max(t1& a, t1& b) {
    return (b < a ? a : b);
}

template <class t1>
t1 min(t1& a, t1& b) {
    return (b > a ? a : b);
}

