#include <iostream>
#include <vector>
using namespace std;

// API DOCUMENTATION BELOW. PLEASE FILL THE FOLLOWING API PRIOR TO CODING
/**
 * PURPOSE: To find all Champion Numbers between two given values inclusively
 * PARAMETER: The getChampions function takes two integer values, begin and end, where begin is an integer between 1 and 100 inclusive, and end is a number greater begin but less than or equal to 100
 * RETURN VALUE: The getChampions function returns a vector of all Champion numbers in the given range
 */ 
vector<int> getChampions(int begin, int end) {
    // YOUR CODE HERE

    //Creat a vector for Champion Numbers
    vector<int> championNumbers;

    //For loop that iterates through all numbers in the given range
    for(int i = begin; i <= end; i++)
    {
        //All numbers less than 10 are Champion Numbers
        if(i < 10)
        {
            championNumbers.push_back(i);
        }
        else
        {
            //Split the number into its two digits
            int firstDigit = i / 10;
            int secondDigit = i % 10;

            //Numbers ending in 0 cannot be Champion Numbers
            if(secondDigit == 0)
            {
                continue;
            }
            else
            {
                //Check if the current number is a Champion Number
                if(i % firstDigit == 0 && i % secondDigit == 0)
                {
                    //Add Champion Numbers to the vector
                    championNumbers.push_back(i);
                }
            }
        }
    }

    return championNumbers;
}
int main()
{
    // your target function will be tested as such, 
    // with a random begin and end value such as:
    vector<int> a = getChampions(1, 22);
    
    // this is one example to print out your vector content
    // in the ascending order
    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    return 0;
}
