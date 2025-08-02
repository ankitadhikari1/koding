class Solution {
public:

    void fill(int i,int j,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
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
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0){
                    grid[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }

        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int j=0;j<m;j++){
            if(grid[0][j]==0)
            fill(0,j,grid);

            if(grid[n-1][j]==0)
            fill(n-1,j,grid);
        }
        for(int i =0;i<n;i++){
            if(grid[i][0]==0)
            fill(i,0,grid);

            if(grid[i][m-1]==0)
            fill(i,m-1,grid);
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    cnt++;
                    fill(i,j,grid);
                }
            }
        }

        return cnt;
    }
};