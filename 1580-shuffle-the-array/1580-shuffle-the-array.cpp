class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];       // xi
            ans[2 * i + 1] = nums[i + n]; // yi
        }
        return ans;
    }
};
