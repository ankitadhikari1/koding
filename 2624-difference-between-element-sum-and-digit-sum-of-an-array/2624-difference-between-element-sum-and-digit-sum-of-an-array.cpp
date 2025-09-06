class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int digitSum = 0;
        for(auto &it : nums){
            while(it){
                int r = it%10;
                digitSum+=r;
                it/=10;
            }
        }
        return abs(sum-digitSum);
    }
};