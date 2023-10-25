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

    //Find out how many dollars there are
    int dollars = numPennies / 100;
    cout << "In US currency you have: ";
    cout << dollars << " dollars, ";

    //Find out how many remaining cents there are    
    float cents = (numPennies - (dollars * 100)) * 0.01;
    //Save the total amount of money in the format $##.## for use later in converting Canadian currency
    float money = dollars + cents;

    //Find remaining pennies
    int remainingPennies = numPennies % 100;

    //Find out how many quarters there are
    int quarters = remainingPennies / 25;
    cout << quarters << " quarters, ";

    //Find remaining pennies
    remainingPennies -= 25 * quarters;
    
    //Find out how many dimes there are
    int dimes = remainingPennies / 10;
    cout << dimes << " dimes, ";

    //Find remaining pennies
    remainingPennies -= 10 * dimes;
    
    //Find out how many nickels there are
    int nickels = remainingPennies / 5;
    cout << nickels << " nickels, ";

    //Find last remaining pennies
    remainingPennies -= 5 * nickels;
    cout << "and " << remainingPennies << " pennies." << endl;

    //Convert pennies to Canadian dollars
    float CAD = money * 1.33;
    cout << "In Canadian currency you have: " << CAD << " dollars.";

    return 0;
}