#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

void AlgebraicRules()
{
    // Presedence
    // Stuff in parentheses has priority
    cout << "4 * 3 + 2 = " << 4 * 3 + 2 << endl;

    cout << "4 * (3 + 2) = " << 4 * (3 + 2) << endl;


    // Associativity
    // Assignment expressions are evalueated right to left
    int i = 1;
    int j = 2;
    cout << "i: " << i << " j: " << j << endl;

    i += j += 2;
    cout << "i += i + j += 2;" << endl;
    cout << "i: " << i << " j: " << j << endl;
}

void CAndCppStrings()
{
    // C string
    // C strings are arrays of characters
    char c_string[] = "C string";
    // c strings add a null terminator at the end of the array, making the size of the array 1 larger than the characters in the string
    cout << "[" << c_string << "] size = " << sizeof(c_string) << endl;

    // C++ string
    // C++ strings are classes
    // Since C++ strings are classes, they have methods that can be used with them
    // You can get the length of a string by using the .length() method
    string cpp_string = "C++ string";
    cout << "\"" << cpp_string << "\" size = " << cpp_string.length() << endl;

    // C string libraries
    // You can include <cstring> or <string.h> to get access to functions for use with cstrings such as strlen
    cout << "[" << c_string << "] strlen = " << strlen(c_string) << endl;
}

void SwitchCases()
{
    // Switch statments route code based on a condition, similar to if, else if, else
    // If you have an if/else if/else branch that has a lot of statments that only use == then you can turn that into a switch statment
    int number;
    cout << "Enter a number between 1 and 4: ";
    cin >> number;

    // The switch statement takes a constant as an expression, in this case 'number'
    switch(number)
    {
        // The switch will check if the expression matches the condition of each case
        case 1:
            cout << "Odd" << endl;
            break; // Switch statements do not stop once a condition has matched. So you need a break to stop the swtich from running code in the rest of the cases
        case 2:
            cout << "Even" << endl;
            break;
        case 3:
            cout << "Odd" << endl;
            break;
        case 4:
            cout << "Even" << endl;
            break;
        default: // The default only runs if all other cases did not match. The default does not need a break
            cout << "Not a number between 1 and 4" << endl;
    }

    // Since switches continue executing code until a break has been found, you can have multiple cases run the same code by stacking the cases and only having the last one include code to execute along with a break statement
    char letter;
    cout << "Enter a letter of the alphabet: ";
    cin >> letter;
 
    switch(letter)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "Vowel";
            break;
        case 'y':
            cout << "Sometimes a vowel";
            break;
        default:
            cout << "Not a vowel" << endl;
    }
}

void ConditionalOperators()
{
    // The Conditional (Ternary) Operator let's you set a variable based on a condition
    int a = 2;
    int b = 7;
    // The format of a Conditional operator is this: Condition ? Result1 : Result2
    // If the condition is true, the variable will be set to Result1
    // If the condition is false, the variable will be set to Result2
    int c = (a>b) ? a : b; // If a > b, set x to a, else set x to b
    cout << "(a>b) ? a : b = " << c << endl;

    // You can declare multiple variables of the same type in one line and even use a Conditional Operator this way
    int x = 5, y = 10, max = (x>y) ? x : y;
    cout << "int x = 5, y = 10, max = (x>y) ? x : y" << endl << "max = " << max << endl;
}

int main()
{
    AlgebraicRules();

    CAndCppStrings();

    SwitchCases();

    ConditionalOperators();

    return 0;
}