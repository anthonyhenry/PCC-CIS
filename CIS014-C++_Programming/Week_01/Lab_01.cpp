#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Problem 1
    // Create your first "Hello World" program
    cout << "Hello World";

    cout << endl;

    // Problem 2
    // Print to screen "The CIS14 C++ Programming class" (a) all on one line (b) on five lines, and (c) inside a box using a combination of '_' and '|' characters
    cout << "The CIS14 C++ Programming class" << endl;
    cout << "The" << endl;
    cout << "CIS14" << endl;
    cout << "C++" << endl;
    cout << "Programming" << endl;
    cout << "class" << endl;

    //Problem 3
    // Write C++ statements that declare the following variables: num1, num2, num3, and average.  Store 48 into num1, 31 into num2, and -23 into num3.
    // Write C++ statements that output the values of num1, num2, num3, and average. 
    int num1 = 48;
    int num2 = 31;
    int num3 = -23;
    float average = (num1 + num2+ num3) / 3.0;

    cout << "num1 is " << num1 << endl;
    cout << "num2 is " << num2 << endl;
    cout << "num3 is " << num3 << endl;
    cout << "The average of num1, num2, and num3 is " << setprecision(4) << average; 

    return 0;
}