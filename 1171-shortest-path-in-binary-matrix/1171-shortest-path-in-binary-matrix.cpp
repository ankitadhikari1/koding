class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]!=0)return -1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int step = q.front().first;
            if(row == n-1 && col == m-1)return step;            
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nx = row + i;
                    int ny = col + j;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == 0 ){
                        q.push({step+1,{nx,ny}});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        return -1;
    }
};