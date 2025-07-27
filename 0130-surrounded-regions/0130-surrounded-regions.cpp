class Solution{
public:


    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat){
        int n = mat.size();
        int m = mat[0].size();
        if(row<0 || row>=n )return;
        if(col<0 || col>=m )return;
        if(vis[row][col])return;
        if(mat[row][col]=='X')return;

        vis[row][col] = 1;
        int dx[] = { 0,1,0,-1};
        int dy[] = {-1,0,1,0};
        for(int i=0;i<4;i++){
            int nx = row + dx[i];
            int ny = col + dy[i];
            dfs(nx,ny,vis,mat);
        }
    }



    void solve(vector<vector<char>>&mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !vis[0][j]){
                dfs(0,j,vis,mat);
            }
        }
        for(int j=0;j<m;j++){
            if(mat[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,vis,mat);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,mat);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,mat);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }

      
        
    }
};