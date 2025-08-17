class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int zeros = 0;
        int maxSize = 0;
        while(right < n){
            if(nums[right]==0)zeros++;

            while(zeros > k){
                if(nums[left]==0 && left <= right)zeros--;
                left++;
            }

            maxSize = max(maxSize , right-left+1);
            right++;

        }

        return maxSize;
    }
};