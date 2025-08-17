class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minSum = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int col = 0; col < n; col++) {
            dp[0][col] = matrix[0][col];
        }


        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int up = dp[row - 1][col];

                int upRight = INT_MAX;
                if(col + 1 <= n-1)
                upRight = dp[row - 1][col + 1];

                
                int upLeft = INT_MAX;
                if(col-1 >= 0)
                upLeft = dp[row - 1][col - 1];

                dp[row][col] = matrix[row][col] + min({up, upRight, upLeft});
            }
        }

        for(int col = 0;col < n;col++){
            minSum = min(minSum,dp[m-1][col]);
        }

        return minSum;
    }
};