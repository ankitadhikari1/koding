class Solution {
public:

    int func(int ind, vector<int>&dp){
        if(ind<=1)return 1;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind] = func(ind-1,dp) + func(ind-2,dp);
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return func(n,dp);
    }
};