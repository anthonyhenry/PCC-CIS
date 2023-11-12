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

    if(window_size == 0 || window_size > requests.size())
    {
        return maxHits;
    }


    for(int i = 0; i <= requests.size() - window_size; i++)
    {
        int max = requests.at(i);
        cout << max;
        for(int j = 1; j < window_size; j++)
        {
            cout << ", " << requests.at(i+j);

            if(requests.at(i+j) > max)
            {
                max = requests.at(i+j);
            }
        }
        cout << " | Max = " << max << endl;
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
