class Solution{
public:


    bool isValidFresh(int row, int col , vector<vector<int>>&grid , vector<vector<int>>&vis){
      int n = grid.size();
      int m = grid[0].size();
      if(row<0 || row>= n)return false;
      if(col<0 || col>= m)return false;
      if(vis[row][col])return false;
      if(grid[row][col]==0)return false;
      return true;
    }


    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int rotten = 0;
        int totalOranges = 0;
        int time = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(grid[i][j]==2){
              q.push({i,j});
              vis[i][j] = 1;
              rotten++;
            }
            if(grid[i][j]!=0)totalOranges++;
          }
        }


        while(!q.empty()){
          int k = q.size();
           bool flag = false;
          for(int i=0;i<k;i++){
            pair<int,int> val = q.front();
            q.pop();
            int row = val.first;
            int col = val.second;
            if(grid[row][col]==1){
              grid[row][col] = 2;
            }
            int dx[] = {0,1,0,-1} ;
            int dy[] = {-1,0,1,0} ;
           
            for(int i=0;i<4;i++){
              int nx = row + dx[i];
              int ny = col + dy[i];
              if(isValidFresh(nx,ny,grid,vis)){
                q.push({nx,ny});
                rotten++;
                vis[nx][ny] = 1;
                flag = true;
              }
            }

          }
          if(flag)time++;
        }



        if(totalOranges-rotten>=1)return -1;
        return time;






    }
};