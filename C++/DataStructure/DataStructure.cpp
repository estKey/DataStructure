// DataStructure.cpp : Defines the entry point for the application.
//

#include "DataStructure.h"

using namespace std;

int main()
{
	cout << "Data Structure" << endl;
	try {
		ArrayStack<int>    intStack;
		ArrayStack<string> stringStack;

		intStack.push(7);
		cout << intStack.top() << endl;

		stringStack.push("hello");
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
	}
	return 0;
}
