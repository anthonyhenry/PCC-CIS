#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: The getMaxProfit function recommends the maximum profit an investor can make by placing as many buy and sell orders in the time slice represented by the prices vector
 * PARAMETERS: The getMaxProfit function takes an integer vector of prices listed in chronological order
 * RETURN VALUES: The getMaxProfit function returns the maximum profit an investor can make by placing as many buy and sell orders in the time slice
 */
int getMaxProfit(vector<int> &prices) {
    int maxProfit = 0;

    // Make sure there is more than one item in the vector
    if(prices.size() > 1)
    {
        for(int i = 0; i < prices.size() - 1; i++)
        {
            // Check if next price is more than current price
            if(prices.at(i+1) > prices.at(i))
            {
                // Increase max profit by the price differences
                maxProfit += prices.at(i+1) - prices.at(i);
            }
        }
    }
    return maxProfit;
}

int main() {
    // your target function will be tested as such, with random input like so
    vector<int> arr{3, 1, 5, 2, 4};
    cout << getMaxProfit(arr); // 6
    return 0;
}
