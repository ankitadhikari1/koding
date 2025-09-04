class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>degree(n);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && i!=j){
                    degree[j]++;
                }
            }
        }
        int champion = -1;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                if(champion != -1)return -1;
                champion = i;
            }

        }
        return champion;
    }
};