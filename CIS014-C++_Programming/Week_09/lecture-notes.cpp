#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

// You can declare a function before defining it
int multiply(int, int);

void userDefinedFunctions()
{
    cout << "Enter a number: ";
    int multiplier;
    cin >> multiplier;

    cout << "Enter another number: ";
    int multiplicand;
    cin >> multiplicand;

    cout << "The product of both numbers is " << multiply(multiplier, multiplicand) << endl;
}

// Declaring an add function to be used in the passByValue function later
int add(int, int);

void passByValue()
{
    int a = 5;
    add(a, 15);
    cout << "a: " << a << endl; // a is still 5 here because we did not return a new value for a in the add function
}

// Pass By Pointer demonstration
void pointerManipulation(int* ax, int* ay) // Function that changes the values in the pointers
{
    // ax and ay still hold the memory addresses
    cout << "ax: " << ax << endl;
    cout << "ay: " << ay << endl;

    // Use an * before the variable to manupulate the memory address's content
    *ax += 24;
    *ay -= 8;

    return; // We don't have to return anything because the values were changed in memory
}

void passByPointer()
{
    // Initialize two integer variables
    int a = 8;
    int b = 24;
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    // Include & before a variable to get it's address. Addresses are always hexadecimal
    cout << "&a: " << &a << endl;
    cout << "&b: " << &b << endl;

    // Pass the addresses through the function
    pointerManipulation(&a, &b);

    // Values are changed without needing to be returned because they were changed in memory
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

// Function that takes an array as an argument
double arrayAverage(int size, int ary[])
{
    int sum = 0;
    double avg;

    for(int i = 0; i < size; i++)
    {
        sum += ary[i];
    }

    avg = (double)sum / size;
    return avg;
}

void passingArraysIntoFunctions()
{
    cout << "Give me 5 numbers to average." << endl;

    // Declare an array of a constant size
    const int arraySize = 5;
    int arrayToAverage[arraySize];

    // Prompt the user for numbers to fill the array
    for(int i = 0; i < 5; i++)
    {
        cout << "Enter number " << i + 1  << ": ";
        cin >> arrayToAverage[i];
    }

    // Find the average of the array
    double avg = arrayAverage(arraySize, arrayToAverage);
    // Print results
    cout << "Average: " << avg << endl;
}

// Overloaded functions share the same function name but may have a different number of arguments or argument types
// At run time, the compiler will determine which function to use based on the arguments provided. This is known as overload resolution
int overloadedFunctions(int x, int y)
{
    return 1;
}
int overloadedFunctions(int x, int y, int z)
{
    return 2;
}
int overloadedFunctions(int x, double y)
{
    return 3;
}
int overloadedFunctions(float x, float y)
{
    return 4;
}

// Inline functions are placeholders. The compiler replaces an inline function call with the actual code from the function
inline void newSection()
{
    cout << "---" << endl;
}

// Using typedef you can create your own variable type
const int NUM_STUDENTS = 15;
typedef int grades_array[NUM_STUDENTS]; // Here we have created a type called grades_array which is defined above as an array of 15

// You can even pass your custom defined types as arguments
void calculatedGrades(grades_array arr)
{
    // An array passed into a function is a pointer reference
    cout << arr << endl;
    cout << arr[0] << " : ";
}

void typeDeclaration()
{
    // These lines create two variables of type grades_array
    grades_array summer_grades;
    grades_array fall_grades;

    calculatedGrades(summer_grades);
    cout << summer_grades[0] << endl;
}

void readIntArray(const int arr[], int arraySize) // Use const if you are only reading the array and not writing to it
{
    cout << "array[" << arraySize << "]: {";

    for(int i = 0; i < arraySize; i++)
    {
        cout << arr[i];

        if(i < (arraySize - 1))
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

void arraySorting()
{
    int arr[10] = {10, 1, 3, 98, 45, 12, 38, 78, 36, 2};

    readIntArray(arr, 10);

    // Loop through all numbers except for the last one
    for(int i = 0; i < 9; i++)
    {
        // Compare the current number with the next one
        for(int j = (i + 1); j < 10; j++)
        {
            // Check if the next number is smaller than the one before it
            // cout << arr[i] << " : " << arr[j] << endl;
            if (arr[j] < arr[i])
            {
                // Swap positions
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    readIntArray(arr, 10);
}

// To use rand(), you need to include <cstdlib>
int randomNumberGenerator(int max)
{
    // Set a seed to simulate randomness. You only need to seed randomness once in your program
    srand(time(NULL)); // The time() function is included in <time.h>

    return (rand() % max) + 1;
}

int main()
{
    userDefinedFunctions();
    newSection();

    passByValue();
    newSection();

    passByPointer();
    newSection();

    passingArraysIntoFunctions();
    newSection();

    int oF;
    oF = overloadedFunctions(2, 5);
    cout << "overloadedFunctions(2, 5) runs overload function number " << oF << endl;
    oF = overloadedFunctions(2, 5, 10);
    cout << "overloadedFunctions(2, 5, 10) runs overload function number " << oF << endl;
    oF = overloadedFunctions(2, 3.0);
    cout << "overloadedFunctions(2, 3.0) runs overload function number " << oF << endl;
    oF = overloadedFunctions(2.5f, 5.1f);
    cout << "overloadedFunctions(2.5, 5.1) runs overload function number " << oF << endl;

    newSection();

    typeDeclaration();
    newSection();

    arraySorting();
    newSection();

    cout << "Rolling a D20: " << randomNumberGenerator(20);

    return 0;
}

// multiply function is defined down here
int multiply(int num1, int num2)
{
    return num1 * num2;
}

int add(int x, int y)
{
    x = x + y;
    return 0;
}

