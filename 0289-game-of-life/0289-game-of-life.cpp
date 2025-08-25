class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> temp = board;  

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                int live = 0;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (i == 0 && j == 0) continue;          
                        int nx = row + i, ny = col + j;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && temp[nx][ny] == 1)
                            ++live;
                    }
                }
                int val = temp[row][col];                         
                if (val == 1) {
                    if (live < 2 || live > 3) board[row][col] = 0;
                    
                } else {
                    if (live == 3) board[row][col] = 1;
                }
            }
        }
    }
};
