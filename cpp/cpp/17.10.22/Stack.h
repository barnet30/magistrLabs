#pragma once
#include <vector>
#include <iostream>

template<typename T>
class Stack {
private:
	std::vector<T> v;
public:
	void push(T const& v);
	void pop();
	T const& top() const;
	bool empty() const {
		return v.empty();
	}
	template<typename T> 
	friend std::ostream& operator<<(std::ostream& out, const Stack<T>& s);
};

template <typename T>
void Stack<T>::push(T const& e) {
    v.push_back(e);
}

template <typename T>
void Stack<T>::pop() {
    if(!v.empty())
		v.pop_back();
}

template <typename T>
T const& Stack<T>::top() const {
    if(!v.empty())
		return v.back();
}

template<typename T>
std::ostream& operator<<(std::ostream& out, Stack<T> const &s) {
	for (auto a : s.v)
		out << a << ' ';
    return out;
}