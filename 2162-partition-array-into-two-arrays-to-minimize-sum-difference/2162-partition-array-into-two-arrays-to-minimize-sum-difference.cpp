
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        // Generate all subset sums
        auto genSums = [](vector<int>& arr) {
            int m = arr.size();
            vector<vector<int>> sums(m + 1);
            for (int mask = 0; mask < (1 << m); mask++) {
                int sum = 0, bits = __builtin_popcount(mask);
                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) sum += arr[i];
                }
                sums[bits].push_back(sum);
            }
            for (auto& v : sums) sort(v.begin(), v.end());
            return sums;
        };

        auto leftSums = genSums(left);
        auto rightSums = genSums(right);

        int res = INT_MAX;

        // Match subsets
        for (int k = 0; k <= half; k++) {
            auto& L = leftSums[k];
            auto& R = rightSums[half - k];

            for (int s : L) {
                int need = totalSum / 2 - s;
                auto it = lower_bound(R.begin(), R.end(), need);
                if (it != R.end())
                    res = min(res, abs(totalSum - 2 * (s + *it)));
                if (it != R.begin()) {
                    --it;
                    res = min(res, abs(totalSum - 2 * (s + *it)));
                }
            }
        }
        return res;
    }
};
