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
        // cout << "ver1[" << i << "]: " << ver1[i] << endl;
        // Check if a decimal point has been reached
        if(ver1[i] == '.')
        {
            // Set the end of the partition
            endOfVer1Number = i;
            // Create an empty string variable for holding the partition's number
            string ver1PartitionNumberString = "";

            // cout << "Start: " << startOfVer1Number << endl;
            // cout << "End: " << endOfVer1Number << endl;

            // Get the whole number for this partition
            for(int j = startOfVer1Number + 1; j < endOfVer1Number; j++)
            {
                // cout << "ver1[j]: " << ver1[j] << endl;
                ver1PartitionNumberString += ver1[j];
            }

            // Integer variable Convert partition number from a string to an integer
            int ver1ComparisonNumber = stoi(ver1PartitionNumberString);
            int ver2ComparisonNumber; // The value of this will be set later

            // Get the whole number for the next ver2 partition
            for(int k = startOfVer2Number + 1; k < longerVersionLength; k++)
            {
                // Check if a decimal point has been reached
                if(ver2[k] == '.')
                {
                    // cout << "Found a decimal point in ver2!" << endl;
                    // Set the end of the partition
                    endOfVer2Number = k;
                    // Create an empty string variable for holding the partition's number
                    string ver2PartitionNumberString = "";

                    // Get the whole number for this partition
                    for(int l = startOfVer2Number + 1; l < endOfVer2Number; l++)
                    {
                        ver2PartitionNumberString += ver2[l];
                    }

                    // cout << "ver2PartitionNumberString " << ver2PartitionNumberString << endl; 

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

            // cout << ver1PartitionNumberString << endl;

            cout << "Comparing " << ver1ComparisonNumber << " to " << ver2ComparisonNumber << endl;



        }
    }

    
    return -1;
}
int main() {
    // your target function will be tested as such, with 
    // random input. To streamline your testing, you may
    // also test your own code this way:
    // cout << (compareVersions("0.1", "0.1") == 0); // 1, which is true
    // cout << compareVersions("0.1", "0.1"); // 0
    cout << compareVersions("0.123.5.5.4", "6.7.1");
    return 0;
}
