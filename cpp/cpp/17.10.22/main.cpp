#include <iostream>
#include "QueuePtr.h"
#include "StackPair.h"

int main()
{
    cout << "TASK 1\n";
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

    cout << "\nTASK 2\n";

    Stack<double> stack;
    stack.push(3.14);
    cout << "Top: " << stack.top() << endl;
    stack.push(2.67);

    cout << "Stack: " << stack << endl;

    stack.pop();
    cout << "After pop: " << stack << endl;

    Stack<pair<string, int>> pairStack;
    pairStack.push(make_pair("sss", 1));
    pairStack.push(make_pair("wrwr", 2));

    cout << "Pair stack: " << pairStack << endl;

    pairStack.pop();
    cout << "Pair stack after pop: " << pairStack << endl;

    return EXIT_SUCCESS;
}
