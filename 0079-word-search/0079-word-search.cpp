class Solution {
public:

    bool func(int row,int col,vector<vector<char>>&board,string word,int ind,vector<vector<int>>&vis){
        int n = board.size();
        int m = board[0].size();

        

        if(row>=n || row<0 || col>=m || col<0 || vis[row][col]==1){
            return false;
        }

        if(board[row][col]!=word[ind])return false;

        if(ind == word.size()-1){
            return true;
        }


         int dx[] = {-1, 0, 1, 0}; 
         int dy[] = {0, 1, 0, -1};  

        vis[row][col] = 1;
        bool flag = false;
        for(int i=0;i<4;i++){
            int newX = row + dx[i];
            int newY = col + dy[i];
            flag |= func(newX,newY,board,word,ind+1,vis); 
        }

        vis[row][col] = -1;
        return flag;





    }




    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    bool flag = func(i,j,board,word,0,vis);
                    if(flag==true)return true;
                }
            }
            
        }
        return false;
    }
};