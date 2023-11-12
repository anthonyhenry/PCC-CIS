#include <iostream>
#include <vector>

using namespace std;

class CIS14 {
public:
     vector<int> getMaxHits(vector<int> &requests, int window_size);
};

// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class 
// named CIS14 with its method you will implement.
// ------------------------------------------------------------

/**
 * PURPOSE: To find the maximum number of hits a site recieves in a given window
 * PARAMETERS: The function getMaxHits takes two parameters. A vector of requests, and an integer for the window size to search for max hits
 * RETURN VALUES: The function getMaxHits returns a vector of integers for the max hits recieved in the specified window size
 */
vector<int> CIS14::getMaxHits(vector<int> &requests, int window_size) {
    // Create an empty vector to hold max values
    vector<int> maxHits;

    // If the window size is 0, or larger than the size of the requests vector, return an empty vector
    if(window_size == 0 || window_size > requests.size())
    {
        return maxHits;
    }

    // Loop through the requests vector, stop at the length of the requests vector minus the window size parameter value
    for(int i = 0; i <= requests.size() - window_size; i++)
    {
        // Temporary variable for storing the local max
        int max = requests.at(i);
        cout << max;
        // Loop through the next values in the requests vector as specified by the window size argument
        for(int j = 1; j < window_size; j++)
        {
            cout << ", " << requests.at(i+j);
            // Update the local max variable if a new local max has been found
            if(requests.at(i+j) > max)
            {
                max = requests.at(i+j);
            }
        }
        cout << " | Max = " << max << endl;
        // Add the max variable to the maxHits vector
        maxHits.push_back(max);
    }

    return maxHits;
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;    
    
    // Your target method will be tested with random input such
    // as the following example; the actual test cases will vary
    vector<int> v = /*{1,2,4}*/ {0,0,0};
    vector<int> ans = cis14.getMaxHits(v,/*1*/10);
    
    // You may use the following code to print out your returned vector's content
    for (int i=0; i<ans.size(); i++) cout << ans[i] << ((i==ans.size()-1) ? "" : ",");
    
    return 0;
}
