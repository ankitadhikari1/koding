class Solution {
public:

    int func(int row , int col ,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row < 0 || col < 0 )return INT_MAX;
        if(row == 0 && col == 0)return grid[row][col];
        if(dp[row][col]!=-1)return dp[row][col];
        int up = func(row-1,col,grid,dp);
        int left = func(row,col-1,grid,dp);
        return dp[row][col] = grid[row][col] + min(up,left);
    }


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,grid,dp);
    }
};