class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1])return -1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if(row == n-1 && col == m-1)return dist;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nx = row + i;
                    int ny = col + j;
                    if(nx>=0 && nx < n && ny >=0 && ny< m && grid[nx][ny]==0 && !vis[nx][ny]){
                        vis[nx][ny] = 1;
                        q.push({{nx,ny},dist+1});
                    }
                }
            }
        }
        return -1;

    }
};