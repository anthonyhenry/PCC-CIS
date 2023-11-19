#include <iostream>
#include <string.h>

using namespace std;

void constantVariablesExample()
{
    int k = 3;
    // You can place the const keyword before or after the variable type. Thus, these two lines of code do the exact same thing
    const int* ptr = &k;
    int const* ptr2 = &k;

    cout << ptr << endl << ptr2 << endl;
}

int computeCStringLengthUsingPointer(const char* str)
{
    // Initialize a variable for counting the length of the c string
    int cStringLength = 0;

    // The argument str is a pointer that points to the very first character of the C string
    cout << *str << endl << "---" << endl; // Dereferenceing str gets you the value in the memory address

    // Loop through the c string until reaching the \0 terminator
    while(*str != '\0')
    {
        // Display the character at the pointer's current location
        cout << *str << " : "; 
        cStringLength++;
        cout << cStringLength << endl;
        // Increment the pointer location
        str++;
    }

    cout << "Length: " << cStringLength << endl;
    // Return the c string length
    return cStringLength;
}

// CRect class declaration
class CRectangle
{
    // There are three access specifiers in c++
        // 1. Public
            // public member variables and methods can be directly accessed outside of the class
        // 2. Private
            // private member variables and methods cannot be directly accessed outside of the class
            // private is the default access specifier. So variables or methods are private unless otherwise denoted as public or private
        // 3. Protected
            // protected member variables and methods cannot be directly accessed outside of the class with the exception of child classes

    // Private properties.
    int x;
    int y;

    // Public properties.
    public:
        // set_values member function declaration. This functin gets defined below using the class scope operator
        void set_values(int, int);
        // You can also define this function inline shown below. In line definitions are used for member functions that don't require a lot of lines of code
        // void set_values(int a, int b){x=a; y=b;}
        
        // area member function declaration 
        int area(void);
        // In line member function definition for area() shown below
        // int area() {return (x*y);}
};

// Member function definition for set_values() function
void CRectangle::set_values(int a, int b)
{
    x = a;
    y = b;
}

// // Member function definition for area() function
int CRectangle::area()
{
    return x * y;
}

int main()
{
    constantVariablesExample();

    char cString[] = "This is a C string.";
    cout << cString << endl;

    computeCStringLengthUsingPointer(cString);
    // Use strlen() just to make sure the function above worked
    cout << "strlen(cString) = " << strlen(cString) << endl;

    // Create two rectangles of type CRectangle
    CRectangle rectangle1, rectangle2;
    // Use the member function set_values() to set x and y for each rectangle
    rectangle1.set_values(3,4);
    rectangle2.set_values(5,6);
    // Now use the area() member funtion to calculate area of each rectangle
    cout << "rectangle1 area: " << rectangle1.area() << endl;
    cout << "rectangle2 area: " << rectangle2.area() << endl;

    return 0;
}