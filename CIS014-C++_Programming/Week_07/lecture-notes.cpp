#include <iostream>
#include <assert.h>

using namespace std;

// Methods (or member functions) are functions that are a part of a class
// Methods are called using the '.' operator. Ex: name.length()

// Functions must be defined before they are called
int addTwoNumbers(int number1, int number2) // Parameters are a part of a function, arguments are what gets passed through. In this case number1 and number2 are parameters
{
    int sum = number1 + number2;
    cout << number1 << " + " << number2 << " = ";
    assert(sum == 5); // You can use assertions to help with debugging. If the boolean statement in the assert call is false, an Assertion failed message will display in the console
    return sum; // The return type must match the type declared in the function
}

int arrayCount = 1;

// When you pass an array into a function, you are actually passing the memory address for each index
void readIntArray(const int arr[], int arraySize) // Use const if you are only reading the array and not writing to it
{
    cout << "array" << arrayCount << "[" << arraySize << "]: {";

    for(int i = 0; i < arraySize; i++)
    {
        cout << arr[i];

        if(i < (arraySize - 1))
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    arrayCount++;
}

void readStringArray(const string arr[], int arraySize)
{
    cout << "array" << arrayCount << "[" << arraySize << "]: {";

    for(int i = 0; i < arraySize; i++)
    {
        cout << arr[i];

        if(i < (arraySize - 1))
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    arrayCount++;
}

void readCharArray(const char arr[], int arraySize)
{
    cout << "array" << arrayCount << "[" << arraySize << "]: {";

    for(int i = 0; i < arraySize; i++)
    {
        cout << arr[i];

        if(i < (arraySize - 1))
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    arrayCount++;
}

void arrays()
{
    // Different ways to declare arrays

    int array1[6] = {}; // Declaring this way will lead all values to be 0
    readIntArray(array1, sizeof(array1) / sizeof(array1[0])); // one way to find the size of an array is to divde the total memory of the array by the memory size of the data type

    // Uniform initialization
    string array2[2] = {"one", "two"}; 
    readStringArray(array2, sizeof(array2) / sizeof(array2[0]));

    // Implicit initialization
    int array3[] = {1, 2, 3};
    readIntArray(array3, sizeof(array3) / sizeof(array3[0]));

    // Partial initialization. The uninitialized values for the array will be equal to 0 (might not be correct)
    int array4[15] = {1, 2}; 
    readIntArray(array4, sizeof(array4) / sizeof(array4[0]));

    // Initialize all to same value. Might not work this way
    char array5[10] = { 'z' }; 
    readCharArray(array5, sizeof(array5) / sizeof(array5[0]));

    // Inizialize by user input
    const int arrayLength = 4;
    int array6[arrayLength]; // When using a variable to set an array length it is best practice for that variable to be a constant
    cout << "Please enter " << arrayLength << " integers:" << endl;
    for(int i = 0; i < (sizeof(array6) / sizeof(array6[0])); i++)
    {
        cin >> array6[i];
    }
    readIntArray(array6, sizeof(array6) / sizeof(array6[0]));
}

void dynamicMemoryAllocation()
{
    // Array's require continuos memory (adjacent)
    // For large array's, you may not have that much continuous memory, so you need to use dynamic memory allocation otherwise you will run into a segmentation fault
    const int dynamicMemoryAllocationArrayLength = 10000000;
    // Dynamic memory allocation uses memory from the heap instead of the stack. More memory is available in the heap than the stack
    // Dynamic memory allocation requires to steps that can be combined together
    // 1. Pointer declaration. The * character denotes a pointer
    // 2. Memory allocation. The new keyword indicates memory allocation
    int* array = new int[dynamicMemoryAllocationArrayLength]; // This declares an array of pointers. The pointers point to the heap location of each item
    
    for(int i = 0; i < dynamicMemoryAllocationArrayLength; i++)
    {
        array[i] = i;
    }

    // readIntArray(array, dynamicMemoryAllocationArrayLength);
    
    // When something is dynamically allocated, you need to de-allocate it when done. The two lines below are how you de-allocate otherise you will have memory leaks
    delete[] array; // Deallocate memory reserved for array
    array = NULL; // Set array in memory to NULL

    // int array[1000000];
    // readIntArray(array, sizeof(array) / sizeof(array[0]));
}

int main ()
{
    cout << addTwoNumbers(2,3) << endl;
    arrays();
    dynamicMemoryAllocation();
    return 0;
}