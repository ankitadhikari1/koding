class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>>mat(n+1,vector<bool>(n+1,false));
        vector<int>degree(n+1,0);
        for(auto & it : edges){
            mat[it[0]][it[1]] = true;
            mat[it[1]][it[0]] = true;
            degree[it[0]]++;
            degree[it[1]]++;
        }
        int ans = INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j= i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(mat[i][j] && mat[j][k] && mat[k][i]){
                        ans = min(ans,degree[i]+degree[j]+degree[k]-6);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};