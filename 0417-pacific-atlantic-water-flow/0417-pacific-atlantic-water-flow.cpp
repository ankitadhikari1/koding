class Solution {
public:

    void dfs(int row , int col , vector<vector<bool>>&vis , vector<vector<int>>&heights){
        int n = heights.size();
        int m = heights[0].size();
        vis[row][col] = 1;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nx = row + dx[i];
            int ny = col + dy[i];
            if(nx >= 0 && nx < n && ny >=0 && ny < m && !vis[nx][ny] && heights[nx][ny] >= heights[row][col] ){
                dfs(nx,ny,vis,heights);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            dfs(i,0,pac,heights);
            dfs(i,m-1,atl,heights);
        }

        for(int j=0;j<m;j++){
            dfs(0,j,pac,heights);
            dfs(n-1,j,atl,heights);
        }

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

    }
};