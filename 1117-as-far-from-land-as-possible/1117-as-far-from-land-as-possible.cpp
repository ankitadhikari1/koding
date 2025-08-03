class Solution {
public:


    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }

        if(q.empty()||q.size()==n*m)return -1;
        int dx[] = {0,1,0,-1};
        int dy[] = {-1,0,1,0};
        int maxDist = 0;
        while(!q.empty()){

            int size = q.size();
            while(size--){
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx>=0 && nx< n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==0){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            }
            maxDist++;

        }

        return maxDist-1;



    }
};