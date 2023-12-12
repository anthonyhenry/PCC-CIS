#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: The getMaxProfit function recommends the maximum profit an investor can make by placing one buy and one sell order in the time slice represented by the prices vector 
 * PARAMETERS: The getMaxProfit function takes an integer vector of prices listed in chronological order
 * RETURN VALUES: The getMaxProfit function returns the maximum profit an investor can make by placing just one buy and sell order
 */
int getMaxProfit(vector<int> &prices) {
    // Variable to hold max profit return value
    int highestProfit = 0;

    // Make sure there is more than one item in the vector
    if(prices.size() > 1)
    {
        // Working backwards, look for the highest price in the vector
        int highestPrice = 0;
        for(int i = prices.size() - 1; i > 0; i--)
        {
            if(prices.at(i) > highestPrice)
            {
                // New highest price found
                highestPrice = prices.at(i);

                // Look for the lowest price that comes before the new highest price
                int lowestPriceBeforeHighestPrice = prices.at(i); // Initialize this varaible to be the same as highest price to start
                for(int j = i - 1; j >= 0; j--)
                {
                    if(prices.at(j) < lowestPriceBeforeHighestPrice)
                    {
                        lowestPriceBeforeHighestPrice = prices.at(j);
                        // Find the difference between the highest price and the lowest price before it
                        int profit = highestPrice - lowestPriceBeforeHighestPrice;
                        // Check if a new highest profit has been found
                        if(profit > highestProfit)
                        {
                            highestProfit = profit;
                        }
                    }
                }    
            }
        }
    }

    return highestProfit;
}
int main() {
    // your target function will be tested as such, with random input like so
    vector<int> arr{1, 2, 4};
    cout << getMaxProfit(arr); // 3
    return 0;
}
