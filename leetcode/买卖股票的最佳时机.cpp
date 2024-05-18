#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;




class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        if(n == 0){
            return 0;
        }

        int dp_i_0 = 0;
        int dp_i_1 = -prices[0];

        for(int i = 1; i<n ; i++)
        {
            dp_i_1 = std::max(dp_i_1, -prices[i]);
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);

        }
        return dp_i_0;

    }
};