class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalOranges = 0;
        int rottenOranges = 0;
        int time = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    rottenOranges++;
                    q.push({i,j});
                }
                if(grid[i][j]!=0)totalOranges++;
            }
        }

        if(totalOranges==0)return 0;

        while(!q.empty()){
            time++;
            int size = q.size();
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};
            for(int i=0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = dx[i] + row;
                    int ny = dy[i] + col;
                    if(nx>=0 && nx < n && ny>=0 && ny < m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        rottenOranges++;
                        q.push({nx,ny});
                    }
                }
            }

        }

        if(rottenOranges == totalOranges)return time-1;
        return -1;
    }
};