class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first.first;
            int col = node.first.second;
            int step = node.second;
            dist[row][col] = step;
            int dx[] = {0,1,0,-1};
            int dy[] = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int nx = row+dx[i];
                int ny = col+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]!=0){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny},step+1});
                }
            }
        }

        return dist;
    }
};