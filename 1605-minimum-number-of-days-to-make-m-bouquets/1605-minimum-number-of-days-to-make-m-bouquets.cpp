class Solution {
public:

     int func(vector<int>& nums, int k, int m, int day) {
        int bouquets = 0, flowers = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets;
    }



    int minDays(vector<int>& nums, int m, int k) {
        if (1LL * k * m > nums.size()) return -1; 
        
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int possible = func(nums, k, m, mid);
            if (possible >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};