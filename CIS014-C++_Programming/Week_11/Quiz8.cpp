#include <iostream>

using namespace std;

void swap_function(int** a, int**b)
{
    // Variable to hold the initial value of a
    int temp = **a;
    // Swap numbers
    **a = **b;
    **b = temp;
}

int main() {
    int x = 5, y = 6;
    int* ptr1 = &x;
    int* ptr2 = &y;
    swap_function(&ptr1 , &ptr2);
    cout << *ptr1 << *ptr2 ;  // Prints ”65"
    return 0;
}