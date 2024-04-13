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
