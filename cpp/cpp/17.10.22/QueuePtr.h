#pragma once
#include "Queue.h"
using namespace std;

template<class T>
class Queue<T*>
{
private:
	size_t count; 
	size_t capacity; 
	size_t head;
	size_t last;
	T** data; 

public:
	Queue(int size);
	Queue(const Queue& q);
	~Queue();
	size_t size();
	T* front();
	T* back();
	void push(T* value);
	void pop();
	bool isEmpty();
	bool isFull();
};


template<class T>
Queue<T*>::Queue(int size)
{
	count = 0;
	capacity = size;
	head = 0;
	last = -1;

	data = new T * [size];
}

template<class T>
Queue<T*>::Queue(const Queue<T*>& q)
{
	delete[] data;

	count = q.count;
	capacity = q.capacity;
	head = q.head;
	last = q.last;

	data = new T * [capacity];
	for (size_t i = 0; i < count; i++)
		data[i] = q.data[i];
}

template<class T>
Queue<T*>::~Queue()
{
	delete[] data;
}

template<class T>
size_t Queue<T*>::size() {
	return count;
}
template<class T>
bool Queue<T*>::isEmpty() {
	return count == 0;
}

template<class T>
T* Queue<T*>::front() {
	if (!isEmpty())
		return data[head];
}
template<class T>
T* Queue<T*>::back() {
	if (!isEmpty())
		return data[last];
}

template<class T>
void Queue<T*>::push(T* value) {

	if (isFull()) {
		cout << "The queue is already full\n";
		exit(EXIT_FAILURE);
	}

	cout << "Pushing element " << *value << endl;

	last++;
	data[last] = value;
	count++;
}

template<class T>
void Queue<T*>::pop() {
	if (isEmpty()) {
		cout << "Queue is empty\n";
		exit(EXIT_FAILURE);
	}

	cout << "Pop element " << *data[head] << endl;

	for (int i = 0; i < last; i++)
		data[i] = data[i + 1];
	last--;
	count--;
}

template <class T>
bool Queue<T*>::isFull() {
	return (size() == capacity);
}
