class Solution {
public:


    void dfs(int ind, vector<vector<int>>&stones,vector<int>&vis){
        int n = stones.size();
        vis[ind] = 1;
        int r = stones[ind][0];
        int c = stones[ind][1];
        for(int i=0;i<n;i++){
            if(!vis[i] && (stones[i][0]==r || stones[i][1]==c)){
                dfs(i,stones,vis);
            }
        }
    }


    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int groups = 0;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                groups++;
                dfs(i,stones,vis);
            }
        }
        return n - groups;
    }
};