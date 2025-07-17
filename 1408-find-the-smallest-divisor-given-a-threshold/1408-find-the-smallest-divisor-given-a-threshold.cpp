class Solution {
public:

     int func(vector<int>& nums, int divisor) {
        int sum = 0;
        for (auto &it : nums) {
            sum += ceil((double)(it) / (double)(divisor));
        }
        return sum;
    }


    int smallestDivisor(vector<int>& nums, int limit) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = func(nums, mid);  
            
            if (sum <= limit) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};