#include<iostream>

using namespace std;

void memoryAddresses()
{
    // Best practice is to initialize pointers to NULL if you do not need to give it a value yet
    // ALWAYS make sure to set the pointer later. You may run into problems if you try to use the pointer later while it is still set to null
    int* p = NULL; // Can also use nullptr as well. nullptr is actually better
    cout << p << endl; // NULL has a value of 0 at runtime

    int a = -123;
    p = &a;
    cout << p << " " << &a << endl;

    // You can use an asterisk before a pointer variable to get the value inside the memory address, this is known as De-referencing
    cout << *p << endl;

    // Changing the value of the pointer also changes the variable it points to
    *p = 8;
    cout << a << endl;

    a = -12;
    cout << *p << endl;
    cout << *&a << endl; // The * and & cancel each other out, so "*&a" is the same as just "a"
}

void pointerArithmetic()
{
    int arr[3] = {8,9,10};

    cout << arr << endl; // This prints out the memory address of the first element of the array

    // You can use pointer arithemtic to print later elements in the array
    cout << "arr[1] = " << arr[1] << " | &arr[1] = " << &arr[1] << " | arr + 1 = " << arr + 1 << endl;
    cout << "arr[2] = " << arr[2] << " | &arr[2] = " << &arr[2] << " | arr + 2 = " << arr + 2 << endl;

    // You cannot use ++ with an array. Instead you must use a pointer
    int*p = arr;
    p++;
    cout << p << endl;
    // With pointer arithmetic you can go beyond the limits of an array. Though this isn't a good idea since it can lead to unexpected results
    // p += 1000;
    // cout << p << endl;
    
    // cout << arr + 1 << endl; //This prints out the memory address of the second element of the array
}

int main()
{
    memoryAddresses();

    pointerArithmetic();

    return 0;
}