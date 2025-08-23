class Solution{
public:

    int func(int ind , int allowed , int limit , vector<int>&arr,vector<vector<vector<int>>>&dp){
        if(ind == arr.size() || limit == 0){
            return 0;
        }

        if(dp[ind][allowed][limit]!=-1)return dp[ind][allowed][limit];

        int profit = 0;
        if(allowed){
            profit = max(func(ind+1,1,limit,arr,dp), -arr[ind] + func(ind+1,0,limit,arr,dp));
        }
        else{
            profit = max(func(ind+1,0,limit,arr,dp),arr[ind]+func(ind+1,1,limit-1,arr,dp));
        }

        return dp[ind][allowed][limit] = profit;
    }


    int maxProfit(vector<int> arr){
        int n = arr.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,2,arr,dp);
    }
};
