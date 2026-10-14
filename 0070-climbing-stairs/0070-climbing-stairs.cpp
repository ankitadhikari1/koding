class Solution {
public:

    int helper(int n , vector<int>&dp){
        if(n<=1)return 1;
        if(dp[n]!=0)return dp[n];
        return dp[n] = helper(n-1,dp) + helper(n-2,dp);
    }


    int climbStairs(int n) {
        n+=2;
        vector<int>dp(n);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<n;i++){
            dp[i] = dp[i-1] + dp[i-2];
            cout<<dp[i]<<" ";
        }

        return dp[n-1];
    }
};