#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE:
 * PARAMETERS:
 * RETURN VALUES:
 */
vector<int> minusMinusN(vector<int> digits) {
    // YOUR CODE HERE

    // If the last digit is larger than 0 just subtract 1
    if(digits[digits.size()-1] > 0)
    {
        digits[digits.size()-1] -= 1;
    }
    else
    {
        // Go backwards down the vector changing all 0s until the first non zero number is reached
        int iterator = digits.size()-1;
        while(iterator >= 0)
        {
            // Change 0s to 9s
            if(digits[iterator] == 0)
            {
                digits[iterator] = 9;
                // digits[iterator-1] = 0;
                iterator--;
                continue;
            }
            // Change the first non zero number to be 1 less
            else
            {
                digits[iterator] -= 1;
                // If the first digit in the vector is now a 0, remove that element from the vector
                if(iterator == 0 && digits[iterator] == 0)
                {
                    digits.erase(digits.begin());
                }
                break;
            }
        }
    }

    return digits;
}
int main() {
    // your target function will be tested like so, with random input
    vector<int> v {1,0};
    vector <int> retVal = minusMinusN(v); // retVal = [9]
    // etc.
    return 0;
}
