#include <iostream>
using namespace std;
/**
 * PURPOSE: 
 * PARAMETERS:
 * RETURN VALUE:
*/ 
class Solution {
public:
     int getNumPossibleSigns(string*, string*, int);
};
int Solution::getNumPossibleSigns(
            string* letterInventory, 
            string* addresses, 
            int length) {
    
    // Initialize an integer of possible signs to return at the end
    int possibleSigns = 0;

    // Loop through all the addresses in the addresses array
    for(int i = 0; i < length; i++)
    {
        cout << endl << "Now checking: " << addresses[i] << " | size = " << addresses[i].length() << endl;
        // Create a copy of the inventory string that can be freely edited for comparing
        string inventoryCopy = letterInventory[0];

        // Loop through all the letters in the address string
        for(int j = 0; j < addresses[i].length(); j++)
        {
            // Initialize a boolean variable for tracking if a valid match has been found at the end of this loop
            bool matchFound = false;

            // Loop through all the letters in the inventory copy string
            for(int k = 0; k < inventoryCopy.length(); k++)
            // for(int k = inventoryCopy.length() - 1; k >= 0; k--)
            {
                // Skip spaces in the address name and the inventory copy string
                if(addresses[i][j] == ' ')
                {
                    matchFound = true;
                    break;
                }
                if(inventoryCopy[k] == ' ')
                {
                    continue;
                }

                cout << "\tComparing " << addresses[i][j] << "(" << j << ")" << " with " << inventoryCopy[k] << "(" << k << ")" << endl;

                // Check if the letter from the address matches the one in inventory
                if(addresses[i][j] == inventoryCopy[k])
                {
                    cout << "\t\tFound a match for " << addresses[i][j] << "(" << j << ") at " << k << "(" << inventoryCopy[k] << ")" << endl;
                    
                    cout << "\t\t" << inventoryCopy << " | length = " << inventoryCopy.length() << endl;
                    // inventoryCopy.erase(k,1);
                    // Replace the character in the inventory copy string with a space
                    inventoryCopy[k] = ' '; // Can alternatively erase the character with the line above
                    cout << "\t\t" << inventoryCopy << " | length = " << inventoryCopy.length() << endl;
                    // set the matchFound flag to true
                    matchFound = true;
                    // move on to the next character in the address name
                    break;
                }
            }

            // Exit the loop if no match was found
            if(matchFound == false)
            {
                cout << "-- NO MATCH FOUND --" << endl;
                break;
            }
            // Increment possible signs variable if all address letters were matched
            else if(j == addresses[i].length()-1)
            {
                cout << "---SUCCESS! " << addresses[i] << "---" <<  endl;
                possibleSigns++;
            }
        }
    }

    return possibleSigns;
};
int main() {
  // Your code may be tested as follows, with different input values
  Solution solution;
  string inventory = "AAAADFADFA223432112";
  string addresses[] = {"S1","CAD","G2"}; // returns 0
  cout << solution.getNumPossibleSigns(&inventory, 
            addresses, 
            sizeof(addresses)/sizeof(addresses[0]));
}
