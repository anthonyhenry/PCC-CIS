#include <iostream>

using namespace std;

class MyClass								// Use the keyword class to define a custom class. At runtime, classes become objects
{                                   		
    public:									// Access specifier to specify accessibility of attributes. Public means the attributes below are accessible outside the class
        int myNum;							// Member variable (int)
        string myString;					// Member variable (string)
        int myFunction(int x);				// Member function (also called methods). This is only a declaration, the function gets defined below
};											// All class definitions end with semi colons

int MyClass::myFunction(int x)				// To define a member function, you need to use the class scope operator "::" with the class name
{
    return 1;
}

int main()
{
	// Create an instance of MyClass on stack memory
    MyClass myFirstClass;                   // You can think of user defined classes as data types. You can create instances of classes (objects) like declaring a variable
	// Print returned value of the member function
    cout << myFirstClass.myFunction(1);

    return 0;
}

/*
STACK
	Stack is an abstract data type that serves as a collection of elements
	The first element goes on the bottom with newer elements going on top of the last element
	The operation of inserting an element into the stack is knon as a push
	Removing elements from the stack is done by the pop operation
	Push ads an element, pop removes the most recently added element that has not yet been removed - Last In, First Out (LIFO)
	Passing variables into functions by value takes up more space in the stack because the function arguments are copies of the variable arguments.

POINTERS
	A pointer is a variable that stores the memory address of an object
	Pointers have 3 main purposes
		1. To allocate new objects on the heap
		2. To pass functions to other functions
		3. To iterate over elements in arrays or other data structures

REFERENCES
	A reference is a data type
	To declare a reference, use the & symbol
	Ex:
		int k = 5;
		int& j = k; // j is now an alias for k
	References are not pointers!
	They are references to existing data
	Think of a reference as another name for the same variable
	Operations done on one, affect the other
	Once references are bount to an object, they can not be bound to anything else. This is similar to constants

MEMORY
	Static Memory
		Allocated by linker and persist throughout the life of a program

	Stack Memory
		Allocated when variables are declared on stack and when functions are called
		De-allocated when variables and functions are out of scope
		Predicable memory pool with predetermined arbitary amount of memory

	Dynamic Memory (heap)
		Allocated by "new" keywoard
		De-allocated by "delete" keyword
		May introduce fragmentation and less predicable memory pool

	BSS
		Stores unitintialized global, statuc, extern variables

	DATA
		Stores binary executables containing initialized global static, extern variables

	TEXT
		Stores binary executables
*/