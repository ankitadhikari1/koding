class Solution {
public:

    bool func(int row,int col,int ind ,vector<vector<char>>& board, string word,vector<vector<int>>&vis){
       
        int n = board.size();
        int m = board[0].size();
        if(word[ind]!=board[row][col])return false;
        if(ind == word.size()-1)return true;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        bool flag = false;
         vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nx = row + dx[i];
            int ny = col + dy[i];
            if(nx>=0 && nx < n && ny>=0 && ny< m && !vis[nx][ny] ){
                flag|=func(nx,ny,ind+1,board,word,vis);
            }
        }
        vis[row][col] = 0;
        return flag;
    }



    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(func(i,j,0,board,word,vis))return true;
                }
            }
        }
        return false;
    }
};