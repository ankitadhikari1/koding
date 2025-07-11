class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<priority_queue<int>>arr(m);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr[i].push(grid[i][j]);
            }
        }

        int ans = 0;
        for(int i=0;i<grid[0].size();i++){
            int maxE = INT_MIN;
            for(int j = 0;j<grid.size();j++){
                int val = arr[j].top();
                arr[j].pop();
                maxE = max(maxE,val);
            }
            ans+=maxE;
        }
        return ans;

    }
};