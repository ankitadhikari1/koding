class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>ans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][(n-1)-i] = mat[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = ans[i][j];
            }
        }
        
    }
};