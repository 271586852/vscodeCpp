#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>


class Solution {
public:
    vector<int> countBits(int n) {
        
        for(i=0;i<n+1;i++)
        {
            //i转换为二进制数字num
            //遍历num的1的个数
            //放到数组里
            //遍历完成输出
        }
    }
};

class Solution {
public:
    int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 0; i <= n; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }
};