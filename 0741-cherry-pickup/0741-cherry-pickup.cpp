class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // dp[k][i][j] = max cherries with k steps, person1 at (i,k-i), person2 at (j,k-j)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];

        for (int k = 1; k < 2 * n - 1; k++) {
            vector<vector<int>> newDp(n, vector<int>(n, -1));
            for (int i = max(0, k - (n - 1)); i <= min(n - 1, k); i++) {
                for (int j = max(0, k - (n - 1)); j <= min(n - 1, k); j++) {
                    int c1 = k - i, c2 = k - j;
                    if (c1 >= n || c2 >= n || grid[i][c1] == -1 || grid[j][c2] == -1) continue;

                    int best = -1;
                    for (int pi : {i - 1, i}) {
                        for (int pj : {j - 1, j}) {
                            if (pi >= 0 && pj >= 0 && dp[pi][pj] != -1) {
                                best = max(best, dp[pi][pj]);
                            }
                        }
                    }

                    if (best == -1) continue;

                    int cherries = grid[i][c1];
                    if (i != j) cherries += grid[j][c2];
                    newDp[i][j] = best + cherries;
                }
            }
            dp.swap(newDp);
        }
        return max(0, dp[n - 1][n - 1]);
    }
};
