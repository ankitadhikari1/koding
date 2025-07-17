class Solution {
public:

    long long func(vector<int>& nums, int divisor) {
        long long sum = 0;
        for (auto &it : nums) {
            sum += (it + divisor - 1) / divisor;
        }
        return sum;
    }



    int minEatingSpeed(vector<int>& nums, int limit) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = func(nums, mid);  
            
            if (sum <= limit) {

                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};