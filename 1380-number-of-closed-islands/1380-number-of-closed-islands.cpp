class Solution {
public:

    void fill(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        grid[i][j] = 1;
        queue<pair<int,int>>q;
        q.push({i,j});

        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};


        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] == 0){
                    grid[nx][ny] = 1;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }

        }
    }


    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 || row>=n || col < 0 || col>=m || vis[row][col]==1 || grid[row][col]==1 ){
            return;
        }

        grid[row][col] = 1;
        vis[row][col] = 1;

        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};

        for(int i=0;i<4;i++){
            int nx = row + dx[i];
            int ny = col + dy[i];
            dfs(nx,ny,vis,grid);
            
            
        }

    }



    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(grid[0][j]==0)
            fill(0,j,vis,grid);

            if(grid[n-1][j]==0)
            fill(n-1,j,vis,grid);
        }
        for(int i =0;i<n;i++){
            if(grid[i][0]==0)
            fill(i,0,vis,grid);

            if(grid[i][m-1]==0)
            fill(i,m-1,vis,grid);
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }

        return cnt;
    }
};