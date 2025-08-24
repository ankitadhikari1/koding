class Solution {
  public:
   
    int func(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount == 0)return 1;
        if(ind==0){
            return amount % coins[ind] == 0;
        }

        if(dp[ind][amount]!=-1)return dp[ind][amount];

        int notTake = func(ind - 1, amount , coins,dp);
        int take = 0;
        if(coins[ind]<=amount){
            take = func(ind , amount - coins[ind],coins,dp);
        }

        return dp[ind][amount] = (take+notTake);

    }


   int change(int amount,vector<int>&coins) {
    int N = coins.size();
    vector<vector<int>>dp(N,vector<int>(amount+1,-1));
        return func(N-1,amount,coins,dp);
    }
};
