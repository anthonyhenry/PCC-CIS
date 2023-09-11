#include <iostream>
using namespace std;
/**
* PURPOSE: this console program breaks the total number of pennies into 
*          respective USD and CAN denominations, and print the string buffer 
*          containing the entire formatted output string to the console display
* PARAMETERS:
*     	None
* RETURN VALUES:
*     	None
*/
int main() {
    int numPennies = 0;
    cout << "Please enter all of your pennies: " << endl;
    cin >> numPennies;

    // YOUR CODE HERE
    cout << "In US currency you have: ";

    int dollars = numPennies / 100;
    cout << dollars << " dollars, ";

    int remainingPennies = numPennies % 100;
    // cout << endl << "Remaining pennies:" << remainingPennies << endl;

    int quarters = remainingPennies / 25;
    cout << quarters << " quarters, ";

    remainingPennies -= 25 * quarters;
    // cout << endl << "Remaining pennies: " << remainingPennies << endl;

    int dimes = remainingPennies / 10;
    cout << dimes << " dimes, ";

    remainingPennies -= 10 * dimes;
    // cout << endl << "Remaining pennies " << remainingPennies << endl;

    int nickels = remainingPennies / 5;
    cout << nickels << " nickels, ";

    remainingPennies -= 5 * nickels;
    cout << "and " << remainingPennies << " pennies." << endl;

    return 0;
}