class Solution {
public:

    bool func(int i , int j , string word , vector<vector<char>>&board, int ind){
        int n = board.size();
        int m = board[0].size();
        
        if (board[i][j] != word[ind]) return false;

// if this was the last character and it matched -> success
if (ind == (int)word.size() - 1) return true;

        
        char ch = board[i][j];
        board[i][j] = '#';
       
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                bool flag = func(nx,ny,word,board,ind+1);
                if(flag)return flag;
            }
        }

        board[i][j] = ch;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool flag = false;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]==word[0]){
                    flag = func(i,j,word,board,0);
                    if(flag == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};