class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1 , suff = 1;
        int maxSum = INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(pre == 0)pre = 1;
            if(suff ==0)suff = 1;

            pre = pre * nums[i];
            suff = suff * nums[n-i-1];

            maxSum = max(maxSum,max(pre,suff));
        }


        return maxSum;
    }
};