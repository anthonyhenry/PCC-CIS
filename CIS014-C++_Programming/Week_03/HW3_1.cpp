#include <iostream>
using namespace std;

/**
 * PURPOSE: Sort a given string of 'a' and 'b' characters such that all 'a' characters appear before 'b' characters
 * PARAMETERS: The function separateLetters takes in a string consisting ofn only 'a' and 'b' characters
 * RETURN VALUES: The function separateLetters returns the string provided with all 'a' characters appearing before 'b' characters
 */
string separateLetters(string input) {
    // YOUR CODE HERE
    int inputLength = input.length(); // Get the length of the input string
    int aCount = 0; // Variable to count how many a's are in the string
    int bCount = 0; // Variable to count how many b's are in the string

    //Iterate through the input string to find out how many 'a' and 'b' characters there are
    for(int i=0; i<inputLength; i++)
    {
        if(input[i] == 'a')
        {
            aCount++;
        }
        else
        {
            bCount++;
        }
    }

    //Move 'a' characters to the start of the string
    for(int i=0; i < aCount; i++)
    {
        input[i] = 'a';
    }
    //Add 'b' characters after the a characters
    for(int i = aCount; i < inputLength; i++)
    {
        input[i] = 'b';
    }

    //Return the sorted string
    return input;
}

int main() {
    separateLetters("abbbbbbbbaaaaaaa");
    return 0;
}
