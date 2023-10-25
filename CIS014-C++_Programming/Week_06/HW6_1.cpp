#include <iostream>
#include <string>
using namespace std;

/**
* PURPOSE: To determine which of two version numbers is the latest
* PARAMETERS: The function compareVersions takes in two string arguments for the two version numbers to compare
* RETURN VALUES: The function compareVersions returns one of three values based on the compaarison. The funciton returns 1 if ver1 is the latest, -1 if ver2 is the latest, and 0 if both are equal 
*/ 
int compareVersions(string ver1, string ver2) {
    // Versions cannot start with a decimal
    if(ver1[0] == '.')
    {
        ver1 = "0" + ver1;
    }
    if(ver2[0] == '.')
    {
        ver2 = "0" + ver2;
    }

    // Find out how many decimals are in each number
    int ver1NumDecimals = 0;
    int ver2NumDecimals = 0;

    for(int i = 0; i < ver1.length(); i++)
    {
        if(ver1[i] == '.')
        {
            ver1NumDecimals++;
        }
    }
    for(int i = 0; i< ver2.length(); i++)
    {
        if(ver2[i] == '.')
        {
            ver2NumDecimals++;
        }
    }

    // Set both versions to have the same number of decimal points
    if(ver1NumDecimals < ver2NumDecimals)
    {
        while(ver1NumDecimals < ver2NumDecimals)
        {
            ver1 += ".0";
            ver1NumDecimals++;
        }
    }
    else
    {
        while(ver2NumDecimals < ver1NumDecimals)
        {
            ver2 += ".0";
            ver2NumDecimals++;
        }
    }

    // End versions with a decimal. Need this for later
    ver1 += '.';
    ver2 += '.';

    // Initialize partition splitting variables
    int startOfVer1Number = -1; 
    int endOfVer1Number = 0;
    int startOfVer2Number = -1;
    int endOfVer2Number = 0;
    
    // For loop to compare version numbers
    for(int i = 0; i < ver1.length(); i++)
    {
        // Check if a decimal point has been reached
        if(ver1[i] == '.')
        {
            // Set the end of this partition
            endOfVer1Number = i;
            // Create an empty string variable for holding the partition's number
            string ver1PartitionNumberString = "";

            // Get the whole number for this partition
            for(int j = startOfVer1Number + 1; j < endOfVer1Number; j++)
            {
                ver1PartitionNumberString += ver1[j];
            }

            // Reset startOfVer1Number variable
            startOfVer1Number = endOfVer1Number;

            // Create integer variables for comparing numbers
            int ver1ComparisonNumber = stoi(ver1PartitionNumberString);
            int ver2ComparisonNumber; // The value of this will be set later

            // Get the whole number for the next ver2 partition
            for(int k = startOfVer2Number + 1; k < ver2.length(); k++)
            {
                // Check if a decimal point has been reached
                if(ver2[k] == '.')
                {
                    // Set the end of this partition
                    endOfVer2Number = k;
                    // Create an empty string variable for holding the partition's number
                    string ver2PartitionNumberString = "";

                    // Get the whole number for this partition
                    for(int l = startOfVer2Number + 1; l < endOfVer2Number; l++)
                    {
                        ver2PartitionNumberString += ver2[l];
                    }

                    // Reset start of ver2 number variable
                    startOfVer2Number = endOfVer2Number;
                    
                    // Set the integer variable for comparing numbers
                    ver2ComparisonNumber = stoi(ver2PartitionNumberString);

                    // exit this loop
                    break;
                }
            }

            // Compare numbers
            if(ver1ComparisonNumber > ver2ComparisonNumber)
            {
                // Return 1 if ver1 is bigger
                return 1;
            }
            else if(ver2ComparisonNumber > ver1ComparisonNumber)
            {
                // Return -1 if ver2 is bigger
                return -1;
            }
        }
    }

    // If the numbers are the same, return 0
    return 0;
}
int main() {
    // your target function will be tested as such, with 
    // random input. To streamline your testing, you may
    // also test your own code this way:
    // cout << (compareVersions("0.1", "0.1") == 0); // 1, which is true
    cout << compareVersions("0.1", "0.1"); // 0
    return 0;
}
