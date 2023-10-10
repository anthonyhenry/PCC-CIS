#include <iostream>
#include <string>
using namespace std;

/**
* PURPOSE:
* PARAMETERS:
* RETURN VALUES:
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

    // Find out how many decimals are in each version
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

    // Set a variable for the length of the longer version string
    int longerVersionLength = (ver1.length() >= ver2.length()) ? ver1.length() : ver2.length();

    // Initialize partition splitting variables
    int startOfVer1Number = -1; 
    int endOfVer1Number = 0;
    int startOfVer2Number = -1;
    int endOfVer2Number = 0;
    
    // For loop to compare version numbers
    for(int i = 0; i < longerVersionLength; i++)
    {
        // Check if a decimal point has been reached
        if(ver1[i] == '.')
        {
            // Set the end of the partition
            endOfVer1Number = i;
            // Create an empty string variable for holding the partition's number
            string ver1PartitionNumberString = "";

            // Get the whole number for this partition
            for(int j = startOfVer1Number + 1; j < endOfVer1Number; j++)
            {
                ver1PartitionNumberString += ver1[j];
            }

            // Integer variables for comparing numbers
            int ver1ComparisonNumber = stoi(ver1PartitionNumberString);
            int ver2ComparisonNumber; // The value of this will be set later

            // Get the whole number for the next ver2 partition
            for(int k = startOfVer2Number + 1; k < longerVersionLength; k++)
            {
                // Check if a decimal point has been reached
                if(ver2[k] == '.')
                {
                    // Set the end of the partition
                    endOfVer2Number = k;
                    // Create an empty string variable for holding the partition's number
                    string ver2PartitionNumberString = "";

                    // Get the whole number for this partition
                    for(int l = startOfVer2Number + 1; l < endOfVer2Number; l++)
                    {
                        ver2PartitionNumberString += ver2[l];
                    }

                    // Integer variable that converts partition number from string to integer
                    ver2ComparisonNumber = stoi(ver2PartitionNumberString);

                    // Reset start of ver2 number variable
                    startOfVer2Number = endOfVer2Number;

                    // exit this loop
                    break;
                }
            }

            // Reset startOfVer1Number variable
            startOfVer1Number = endOfVer1Number;

            // Compare numbers
            if(ver1ComparisonNumber > ver2ComparisonNumber)
            {
                cout << ver1 << " > " << ver2 << endl;
                return 1;
            }
            else if(ver2ComparisonNumber > ver1ComparisonNumber)
            {
                cout << ver1 << " < " << ver2 << endl;
                return -1;
            }
        }
    }

    cout << ver1 << " = " << ver2 << endl;
    return 0;
}
int main() {
    // your target function will be tested as such, with 
    // random input. To streamline your testing, you may
    // also test your own code this way:
    // cout << (compareVersions("0.1", "0.1") == 0); // 1, which is true
    // cout << compareVersions("0.1", "0.1"); // 0
    cout << compareVersions("0.1.2.3.4.5.6.7", "0.3");
    return 0;
}
