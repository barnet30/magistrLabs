#include <iostream>
#include <string>
#include "Queue.h"

int main()
{
	Queue<int> queInt(5);

	queInt.push(1);
	queInt.push(2);
	queInt.push(3);
	queInt.push(100);

	cout << "Front element: " << queInt.front() << endl;
	cout << "Back element: " << queInt.back() << endl;

	queInt.pop();
	queInt.push(888);

	cout << "The queue of int size is " << queInt.size() << endl << endl;

	Queue<string> queStr(4);

	queStr.push("first");
	queStr.push("second");
	queStr.push("third");
	queStr.push("pwpwpw");

	cout << "Front element: " << queStr.front() << endl;
	cout << "Back element: " << queStr.back() << endl;

	queStr.pop();
	queStr.push("888");
	cout << "The queue of str size is " << queStr.size() << endl;

	queStr.pop();
	queStr.pop();
	queStr.pop();
	queStr.pop();

	if (queStr.isEmpty()) {
		cout << "The queue of strings is empty\n";
	}
	else {
		cout << "The queue of strings is not empty\n";
	}
}