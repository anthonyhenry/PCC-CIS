#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: To determine whether, with a given planted field you can plant n number of avocado seeds in it
 * PARAMETERS: The canPlantAvocados function takes two values, a vector and integer. The vector represents a field for planting avacados and must be made up of only 1's and 0's. The integer represents a number of avacados to determine can be planted in the field
 * RETURN VALUES: The canPlantAvocados function returns a boolean value, true or false, indicating whether the given integer number of avacado seeds can be planted in the field created by the given vector
 */ 

bool canPlantAvocados(vector<int> field, int n) { 
    // Initialize a variable to keep track of how many spaces seeds can be planted
    int availableSpaces = 0;

    // Loop through the vector for spaces to plant seeds
    for (int i = 0; i < field.size(); i++)
    {
        // Check if the first entry is a 0
        if(i == 0 && field.at(i) == 0)
        {
            // Look for the first avacado
            for(int j = i; j < field.size(); j++)
            {
                if(field.at(j) == 1)
                {
                    // Check how far the avacado is
                    int distanceToAvacado = j - i;

                    // Increase the available spaces variable if there is room for more seeds
                    if(distanceToAvacado >= 2)
                    {
                        availableSpaces += distanceToAvacado / 2;
                    }

                    // End this loop
                    break;
                }
            }
        }

        // Check if an avacado has been found
        if(field.at(i) == 1 && i < field.size() - 1)
        {
            // When an avacado is found, look for the next avacado
            for(int j = i + 1; j < field.size(); j++)
            {
                if(field.at(j) == 1)
                {
                    // Check how far apart the avacados are
                    int distanceBetweenAvacados = j - i - 1;

                    // Increase the available spaces variable if there is room for more seeds
                    if(distanceBetweenAvacados >= 3)
                    {
                        availableSpaces += (distanceBetweenAvacados - 1) / 2;
                    }

                    // Jump to the next avacado
                    i = j - 1;
                    break;
                }
            }
        }

        // Check if the vector ends with a 0
        if(i == (field.size() - 1) && field.at(i) == 0)
        {
            // Loop backwards through the vector 
            for (int j = i - 1; j >= 0; j--)
            {
                // Look for the nearest avacado
                if(field.at(j) == 1)
                {
                    // Check how far away the last  avacado is
                    int distanceBetweenAvacados = i - j;

                    // Increase the available spaces variable if there is room for more seeds
                    if(distanceBetweenAvacados >= 2)
                    {
                        availableSpaces += distanceBetweenAvacados / 2;
                    }

                    // Exit this loop
                    break;
                }

                // If there is no avacado check the distance of the while vector
                if(j == 0 && field.at(j) == 0)
                {
                    int distanceBetweenAvacados = i - j;

                    // Increase the available spaces variable if there is room for more seeds
                    if(distanceBetweenAvacados >= 1)
                    {
                        availableSpaces += (distanceBetweenAvacados / 2) + 1;
                    }

                    // Exit this loop
                    break;
                }
            }
        }
    }

    // Return whether n number of avacado seeds can be planted
    if(availableSpaces >= n)
    {
        return true;
    }
    else
    {
        return false;
    }
} 

int main() { 
    // your target function will be tested as such,  
    // with random input 
    vector<int> field = {1,0,1};
    cout << canPlantAvocados(field, 1); // function returns a boolean false, 
                                        // which is 0 in cout 
    return 0; 
}
