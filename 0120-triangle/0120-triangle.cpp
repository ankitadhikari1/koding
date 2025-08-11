class Solution {
public:

    // int f(int i , int j ,vector<vector<int>>& triangle ,vector<vector<int>>&dp){
    //     int n = triangle.size();
    //     if(i==n-1) return triangle[n-1][j];
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int down = triangle[i][j] + f(i+1,j,triangle,dp);
    //     int diag = triangle[i][j] + f(i+1,j+1,triangle,dp);
    //     return dp[i][j] = min(down,diag);
    // }


    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<int>prev(n);
        for(int j =0;j<n;j++){
            prev[j] = triangle[n-1][j];
        }

        for(int i = n-2 ;i>=0;i--){
            vector<int>temp(triangle[i].size());
            for(int j = i ;j>=0;j--){
                int d = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];
                temp[j] = min(d,dg);
            }
            prev = temp;
        }

        return prev[0];
       

    }
};