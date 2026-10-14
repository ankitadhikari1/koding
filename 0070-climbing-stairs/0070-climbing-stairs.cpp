class Solution {
public:

    int helper(int n , vector<int>&dp){
        if(n<=1)return 1;
        if(dp[n]!=0)return dp[n];
        return dp[n] = helper(n-1,dp) + helper(n-2,dp);
    }


    int climbStairs(int n) {
        int first = 0;
        int second = 1;
        int curr;
        for(int i=0;i<n;i++){
            curr = first + second;
            first = second;
            second = curr;
        }

        return second;
    }
};