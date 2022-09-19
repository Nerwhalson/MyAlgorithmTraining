#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int profit = 0, hismin = prices[0], len = prices.size();
        for(int i = 1; i < len; i++)
        {
            hismin = hismin > prices[i] ? prices[i] : hismin;
            profit = profit < prices[i] - hismin ? prices[i] - hismin : profit;
        }

        return profit;
    }
};