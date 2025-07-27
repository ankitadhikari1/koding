class Solution {
public:

    void func(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
      int n = grid.size();
      int m = grid[0].size();
      if(row<0 || row >= n || col < 0 || col >= m || vis[row][col] || grid[row][col]=='0' ){
        return;
      }
      vis[row][col] = 1;
      int dx[] = {-1,0,1,0};
      int dy[] = {0,1,0,-1};
      for(int i=0;i<4;i++){
        int nx = row + dx[i];
        int ny = col + dy[i];
        func(nx,ny,grid,vis);
      }
    }


    int numIslands(vector<vector<char>> &grid){
      int n = grid.size();
      int m = grid[0].size();
      int islands = 0;
      vector<vector<int>>vis(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid[i][j]=='1' && !vis[i][j]){
            islands++;
            func(i,j,grid,vis);
          }
        }
      }
      return islands;
    }
};