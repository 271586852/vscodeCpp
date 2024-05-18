// nums.size() 为数组的大小,sizeof(nums)为数组的大小*数组的元素大小
// insert和push_back的区别

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <set>

using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int size = nums.size();
        vector<int> result;
        set<int>mySet;
        for(auto s:nums)
        {
            mySet.insert(s);
        }
        for(int  i = 1;i <= size ; ++i)
        {
            if(!mySet.count(i))
            {
                result.push_back(i);
            }
        }
        return result;
    }
};