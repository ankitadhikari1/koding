class Solution{
    public:



    bool isValid(int row,int col,int old,vector<vector<int>>&image,vector<vector<int>>&vis){
      int n = image.size();
      int m = image[0].size();
      if(row<0 || row>= n)return false;
      if(col<0 || col>= m)return false;
      if(vis[row][col])return false;
      if (image[row][col] != old) return false;
      return true;
    }



    vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int newColor) {
        int old = image[sr][sc];
        if(old==newColor)return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
          pair<int,int> val = q.front();
          q.pop();
          int row = val.first;
          int col = val.second;
          image[row][col] = newColor;
          vis[row][col] = 1;
          int dx[] = {1,0,-1,0};
          int dy[] = {0,1,0,-1};

          for(int i=0;i<4;i++){
            int nx = row + dx[i];
            int ny = col + dy[i];
            if(isValid(nx,ny,old,image,vis)){
              image[nx][ny] = newColor;
              q.push({nx,ny});
            }
          }
        }

        return image;
    }
};
