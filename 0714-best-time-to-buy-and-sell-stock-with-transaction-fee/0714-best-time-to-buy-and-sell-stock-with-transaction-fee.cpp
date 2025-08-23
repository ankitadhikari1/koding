class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<int> curr(2,0) , prev(2,0);
        

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int allowed = 0; allowed <= 1; allowed++) {
                int profit= 0;
                if (allowed) {
                    profit = max(prev[1],(-1) * arr[ind] + prev[ 0] );
                } else {
                    profit = max(prev[ 0],arr[ind] + prev[ 1] - fee);
                }

                curr[allowed] = profit;
            }
            prev = curr;
        }

        return prev[1];
    }
};