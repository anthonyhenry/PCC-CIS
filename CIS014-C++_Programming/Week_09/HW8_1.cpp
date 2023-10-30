#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE:
 * PARAMETERS:
 * RETURN VALUES:
 */
int getMaxProfit(vector<int> &prices) {
    cout << prices.size() << endl;

    int highestProfit = 0;

    // Make sure there is more than one item in the vector
    if(prices.size() > 1)
    {
        for(int i = prices.size() - 1; i > 0; i--)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                int endPrice = prices.at(i);
                int startPrice = prices.at(j);
                int profit = endPrice - startPrice;

                cout << "Comparing " << endPrice << " - " << startPrice << " : " << profit;

                if(profit > highestProfit)
                {
                    highestProfit = profit;
                    cout << " |New Max Found|";
                }

                cout << endl;
            }
        }
    }

    cout << "Highest Profit: " << highestProfit << endl;

    return highestProfit;
}
int main() {
    // your target function will be tested as such, with random input like so
    vector<int> arr/*{1, 2, 4}*/ {3,1,5,2,4};
    cout << getMaxProfit(arr); // 3
    return 0;
}
