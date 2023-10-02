#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE:
 * PARAMETERS:
 * RETURN VALUES:
 */ 
bool canPlantAvocados(vector<int> field, int n) { 
    // YOUR CODE HERE

    // Initialize a variable to keep track of how many spaces seeds can be planted
    int availableSpaces = 0;

    // Loop through the vector for spaces to plany seeds
    for (int i = 0; i < field.size(); i++)
    {
        // cout << i << ": " << field.at(i) << endl;

        //Check if an avacado has been found
        if(field.at(i) == 1 && i < field.size() - 1)
        {
            //When an avacado is found, look for the next avacado
            for(int j = i + 1; j < field.size(); j++)
            {
                if(field.at(j) == 1)
                {
                    //Check how far apart the avacados are
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
    }

    cout << "Available Spaces: " << availableSpaces << endl;

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
    vector<int> field = {1,0,0,0,0,0,0,0,1};
    cout << canPlantAvocados(field, 1); // function returns a boolean false, 
                                        // which is 0 in cout 
    return 0; 
}
