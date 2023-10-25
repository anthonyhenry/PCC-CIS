#include <iostream>

using namespace std;

int main()
{
    //Write a program that prints the sizes of the following fundamental types, namely, int, float, double, char, string, void, bool. Use the sizeof operator.
    cout << sizeof(int) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(string) << endl;
    cout << sizeof(void) << endl;
    cout << sizeof(bool) << endl;


    //Write a C++ console program that prompts the user on a first name, pay rate/hour, and the number of hours worked then outputs the results along with a salary
    string name;
    float payRate;
    float hours;
    cout << "Enter your first name: ";
    cin >> name;
    cout << "Enter your pay rate per hour: ";
    cin >> payRate;
    cout << "Enter the number of hours you worked last week: ";
    cin >> hours;

    cout << "First name: " << name << endl;
    cout << "Pay Rate: $" << payRate << endl;
    cout << "Hours worked: " << hours << endl;

    float salary = hours * payRate;
    cout << "Salary: $" << salary << endl;

    //Write a C++ console program that prompts the user to input the elapsed time for an event in seconds. The program then outputs the elapsed time in hours, minutes, and seconds.
    cout << "Enter time elapsed in seconds: ";
    int seconds;
    cin >> seconds;
    cout << "Time elapsed in seconds = " << seconds << endl;

    int hours2 = seconds / (60*60);
    int minutes = (seconds / 60) % 60;
    seconds = seconds % 60;

    cout << "The equivalent time in hours:minutes:seconds = " << hours2 << ":" << minutes << ":" << seconds << endl;

    //Write a C++ console program that prompts the user to input a random number (either negative or positive). The program then outputs whether the input number is an even number or not. If even, the program prints a boolean true to the console
    cout << "Input a number and I will tell you if it is even: ";
    int number;
    cin >> number;
    
    if(number % 2 == 0)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    
    return 0;
}