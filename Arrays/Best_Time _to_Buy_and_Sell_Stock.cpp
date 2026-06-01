// maintain minprice ad maxprofit 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < minPrice)
            {
                minPrice = prices[i];
            }

            int profit = prices[i] - minPrice;

            if(profit > maxProfit)
            {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};