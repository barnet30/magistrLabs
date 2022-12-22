#pragma once
using namespace std;

template<class T>
class Queue 
{
	T* data;
	int capacity;
	int head;
	int last;
	int count;

public:
    Queue(int size);     // constructor
    ~Queue();
    void pop();
    void push(T t);
    T front();
    T back();
    int size();
    bool isEmpty();
    bool isFull();
};

template<class T>
Queue<T>::Queue(int size) {
    data = new T[size];
    capacity = size;
    head = 0;
    last = -1;
    count = 0;
}

template<class T>
Queue<T>::~Queue() {
    if (data != nullptr) {
        delete []data;
        data = nullptr;
    }
    capacity = 0;
    head = 0;
    last = 0;
    count = 0;
}

template <class T>
void Queue<T>::pop() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        exit(EXIT_FAILURE);
    }

    cout << "Pop element " << data[head] << endl;

    for (int i = 0; i < last; i++)
        data[i] = data[i + 1];
    last--;
    count--;
}

template <class T>
void Queue<T>::push(T value) {

    if (isFull()) {
        cout << "The queue is already full\n";
        exit(EXIT_FAILURE);
    }

    cout << "Pushing element " << value << endl;

    last++;
    data[last] = value;
    count++;
}

template <class T>
T Queue<T>::front() {
    if (!isEmpty())
        return data[head];
}

template <class T>
T Queue<T>::back() {
    if (!isEmpty())
        return data[last];
}

template<class T>
int Queue<T>::size() {
    return count;
}

template <class T>
bool Queue<T>::isEmpty() {
    return (size() == 0);
}

template <class T>
bool Queue<T>::isFull() {
    return (size() == capacity);
}


class JustInt 
{
public:
    int a;
    JustInt(int temp) {
        a = temp;
    }
    void doSmth() {
        std::cout << a;
    }
};

template<class T>
class ClassTemplate {
public:
    T elem;
    ClassTemplate(T val) {
        elem = val;
    }
    void tmplDoSmth() {
        std::cout << "Hello, world!";
    }
    void tmplDo2() {
        JustInt test(this.elem);
        test.doSmth();
    }
};

int main() {
    ClassTemplate<int> a(2);
    a.tmplDoSmth();
    a.tmplDo2(); // OK


    ClassTemplate<std::string[]> b(new string{ "str1", "str2" });
    b.tmplDoSmth();
    b.tmplDo2(); // should error
}