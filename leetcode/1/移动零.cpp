class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int total = nums.size();
        vector<int>::iterator v1 = nums.begin();
        int count = 0;
        for(int i = 0;i < total;i++){
            if(*v1 == 0){
                v1 = nums.erase(v1);
                count += 1;
            }
            else{
                v1++;
            }
        }
        for(int i = 0;i < count;i++){
            nums.push_back(0);
        }
    }
};


// 迭代器失效问题：
// 在使用范围for循环（for(auto s: nums)）遍历数组nums时，如果在循环中修改nums（如通过erase函数删除元素），会导致迭代器失效。失效的迭代器可能会导致未定义的行为或程序崩溃。

// 索引管理问题：
// 当从nums中删除一个元素后，后面所有元素的位置会向前移动一位，但是在代码中通过变量location来跟踪当前元素的索引。如果元素是0，执行了删除操作，location不会增加，这是正确的；但如果不是0，则location增加1。这种管理方式在没有删除操作时是有效的，但与前面提到的迭代器失效问题相冲突，可能导致跳过某些元素或重复检查某些元素。

// 效率问题：
// 使用erase方法从向量中删除元素通常需要O(n)的时间复杂度，因为它涉及到将删除点之后的所有元素向前移动。在最坏的情况下，如果数组中的所有元素都是0，则这种方法的时间复杂度将接近O(n^2)。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int times = 0;
        int location = 0;
        for(auto s:nums)
        {
            if(s==0){
                times += 1;
                nums.erase(nums.begin() + location);
            }
            else
{            location += 1;
}        }
        for(int j = 0; j<times; j++)
        { 
            nums.push_back(0);
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int times = 0;
        int location = 0;
        for(auto s:nums)
        {
            if(s==0){
                times += 1;
                nums.erase(nums.begin() + location);
            }
            location += 1;
        }
        for(int j = 0; j<times; j++)
        { 
            nums.push_back(0);
        }
    }
};