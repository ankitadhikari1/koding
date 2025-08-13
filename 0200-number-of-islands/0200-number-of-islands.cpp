class Solution {
public:


    void bfs(int row , int col , vector<vector<int>>&vis , vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vis[row][col] = 1;
        q.push({row,col});
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = dx[i] + row;
                int ny = dy[i] + col;
                if(nx>=0 && nx <n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]=='1'){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};