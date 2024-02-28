class Solution {
public:
    int climbStairs(int n) {
        int i;
        int a[45];
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
        for (int m = 3; m <= n; m++)
        {
            a[m]=a[m-1]+a[m-2];
        }
        return a[n];
    }
};