class Solution {
   public:
    int maxProfit(int k ,vector<int> arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));


        for (int ind = n - 1; ind >= 0; ind--) {
            for (int allowed = 0; allowed <= 1; allowed++) {
                for (int limit = 0; limit <= k; limit++) {
                    int profit = 0;
                    if (allowed) {
                        profit = max(dp[ind + 1][1][limit],
                                     -arr[ind] + dp[ind + 1][0][limit]);
                    } else {
                        profit = dp[ind + 1][0][limit];
                        if (limit > 0) {
                            profit = max(profit,
                                         arr[ind] + dp[ind + 1][1][limit - 1]);
                        }
                    }

                        dp[ind][allowed][limit] = profit;
                    }
                }
            }

            return dp[0][1][k];
        }
    };
