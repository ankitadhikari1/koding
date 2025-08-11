class Solution {
public:

    int func(int row , int col1 , int col2 , vector<vector<vector<int>>>&dp,vector<vector<int>>& matrix ){
        int n = matrix.size();
        int m = matrix[0].size();

        if(col1 >= m || col1 <0 || col2 >= m || col2 <0 )return 0;
        if(row == n-1){
            if(col1 == col2){
                return matrix[row][col1];
            }
            else{
                return matrix[row][col1] + matrix[row][col2];
            }
        }

        if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];

        int maxSum = INT_MIN;

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int ans ;
                if(col1==col2){
                    ans = matrix[row][col1] + func(row+1,col1+i,col2+j,dp,matrix);
                }
                else{
                    ans = matrix[row][col1]+matrix[row][col2]+func(row+1,col1+i,col2+j,dp,matrix);
                }
                maxSum = max(maxSum,ans);
            }
        }

        return dp[row][col1][col2] = maxSum;

    }


    int cherryPickup(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(0,0,m-1,dp,matrix);
    
    }
};