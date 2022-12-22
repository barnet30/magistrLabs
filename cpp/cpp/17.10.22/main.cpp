#include <iostream>
#include "QueuePtr.h"

int main()
{
    Queue<int*> queue_ptr(4);

    queue_ptr.push(new int{ 1 });
    queue_ptr.push(new int{ 2 });

    std::cout << "Size = " << queue_ptr.size() << std::endl;
    std::cout << "Front = " << *queue_ptr.front() << std::endl;
    std::cout << "Back = " << *queue_ptr.back() << std::endl;

    queue_ptr.push(new int{ 0 });
    queue_ptr.push(new int{ 100 });

    std::cout << "Size = " << queue_ptr.size() << std::endl;
    std::cout << "Front = " << *queue_ptr.front() << std::endl;
    std::cout << "Back = " << *queue_ptr.back() << std::endl;

    queue_ptr.pop();
    queue_ptr.pop();

    std::cout << "Size = " << queue_ptr.size() << std::endl;
    std::cout << "Front = " << *queue_ptr.front() << std::endl;
    std::cout << "Back = " << *queue_ptr.back() << std::endl;

    queue_ptr.pop();
    queue_ptr.pop();

    if (queue_ptr.isEmpty()) {
        cout << "The queue of ptrs is empty\n";
    }
    else {
        cout << "The queue of ptrs is not empty\n";
    }
}
