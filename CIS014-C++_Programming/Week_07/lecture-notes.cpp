#include <iostream>

using namespace std;

// Methods (or member functions) are functions that are a part of a class
// Methods are called using the '.' operator. Ex: name.length()

// Functions must be defined before they are called
int addTwoNumbers(int number1, int number2) // Parameters are a part of a function, arguments are what gets passed through. In this case number1 and number2 are parameters
{
    int sum = number1 + number2;
    cout << number1 << " + " << number2 << " = ";
    return sum; // The return type must match the type declared in the function
}

int main ()
{
    cout << addTwoNumbers(2,3) << endl;
    return 0;
}