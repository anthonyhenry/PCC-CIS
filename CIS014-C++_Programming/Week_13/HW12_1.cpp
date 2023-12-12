#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class CIS14
{
public:
    int getSignal(vector<int> &);
};
// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class
// named CIS14 with its method and the Node class you will use.
// <climits> is included to accommodate use of INT_MAX and/or INT_MIN.
// ------------------------------------------------------------

/**
 * PURPOSE: 
 * PARAMETERS:
 * RETURN VALUE:
*/
int CIS14::getSignal(vector<int> &ints)
{
    // Check if the vector only has 1 integer in it
    if(ints.size() == 1)
    {
        // Return -1 for a positive number
        if(ints.at(0) > 0)
        {
            return -1;
        }
        // Return 1 for a negatuve number
        else if(ints.at(0) < 0)
        {
            return 1;
        }
        // Return 0 if the number is 0
        else
        {
            return 0;
        }
    }
    // Vector has more than 1 number
    else
    {
        // Initialize a variable for keeping track of the number of negaitve numbers in the vector
        int negativeNumberCount = 0;

        for(int i = 0; i < ints.size(); i++)
        {
            // Check if there is a 0 in the vector
            if(ints.at(i) == 0)
            {
                // Product will be 0, so return 0
                return 0;
            }
            // Count the number of negative numbers in the vector
            else
            {
                if(ints.at(i) < 0)
                {
                    negativeNumberCount++;
                }
            }
        }

        // Check how many negative numbers were in the vector
        if(negativeNumberCount % 2 == 0)
        {
            // If there is an even number of negative numbers, the product will be positive
            return -1;
        }
        else
        {
            // If there is an odd number of negative numbers, the product will be negative
            return 1;
        }

    }
};

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // Your target method will be tested with random input such
    // as the following examples; the actual test cases will vary
    vector<int> v = {1, -1};
    cout << cis14.getSignal(v) << endl; // expects 1
    v = {1, 0, 1, 232, -23, 8, 109};
    cout << cis14.getSignal(v) << endl; // expects 0
    // etc.

    return 0;
}