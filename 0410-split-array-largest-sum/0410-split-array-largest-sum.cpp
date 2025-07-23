class Solution {
public:

    bool canWeDo(vector<int>& nums, int m, int mid) {
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                cnt++;
                sum = nums[i];
            }
        }
        return cnt > m;  
    }


    int splitArray(vector<int>& nums, int m) {
         if (nums.size() < m) return -1;  
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canWeDo(nums, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return low;
    }
};