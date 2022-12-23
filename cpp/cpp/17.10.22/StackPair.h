#pragma once
#include "Stack.h"
#include <utility>

template <typename T1, typename T2>
class Stack<std::pair<T1, T2>> {
private:
    std::vector<std::pair<T1, T2>> v;
public:
    void push(std::pair<T1, T2> const& e);
    void pop();
    std::pair<T1, T2> const& top() const;
    bool empty() const {
        return v.empty();
    };
    template<typename T1, typename T2> 
    friend std::ostream& operator<<(std::ostream& out, const Stack<std::pair<T1, T2>>& s);
};
template <typename T1, typename T2>
void Stack<std::pair<T1, T2>>::push(std::pair<T1, T2> const& e) {
    v.push_back(e);
}

template <typename T1, typename T2>
void Stack<std::pair<T1, T2>>::pop() {
    if (!v.empty())
        v.pop_back();
}

template <typename T1, typename T2>
std::pair<T1, T2> const& Stack<std::pair<T1, T2>>::top() const {
    if (!v.empty())
        return v.back();
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, Stack<std::pair<T1, T2>> const &s) {
    for (auto el : s.v)
        out << "(" << el.first << ", " << el.second << "), ";
    return out;
}