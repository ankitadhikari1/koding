class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int lastCol = grid[row][col];
        queue<pair<int,int>>q;
        q.push({row,col});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<pair<int,int>>border;
        vis[row][col] = 1;
        int dx[] = {0,1,0,-1};
        int dy[] = {-1,0,1,0};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            bool flag = false;
            for(int i=0;i<4;i++){
                int nx = r + dx[i];
                int ny = c + dy[i];
                if(nx<0 || nx >= n || ny<0 || ny>=m || grid[nx][ny]!=lastCol){
                    flag = true;
                }
                else if(!vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            if(flag){
                border.push_back({r,c});
            }

        }

        for(auto &[r,c] : border){
            grid[r][c] = color;
        }

        return grid;
        
    }
};