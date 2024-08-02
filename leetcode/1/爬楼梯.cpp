#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> a(n+1);
        a[0] = 1;
        a[1] = 1;
        for (int m = 2; m <= n; m++)
        {
            a[m] = a[m-1] + a[m-2];
        }
        return a[n];
    }
};