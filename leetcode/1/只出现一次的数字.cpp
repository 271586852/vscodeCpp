#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;


/**
    * Find the number that appears only once in the given vector.
    * 
    * @param nums The vector of integers.
    * @return The number that appears only once.
    */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v;
        v=nums;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++)
        {
            if (i==v.size()-1)
            {
                return v[i];
            }
            if(v[i]!=v[i+1])
            {
                return v[i];
            }
            i++;
        }
        return 0;
    }
};

// 解法二 异或运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(),nums.end(),0,bit_xor());
    }
};

// 解法三 异或运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num : nums) {
            res ^= num;
        }
        return res;
    }
};