class Solution {
public:
    bool validate(int row, int col, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        char num = board[row][col];

       
        for (int i = 0; i < n; i++) {
            if (i != row && board[i][col] == num) return false;
        }

        
        for (int j = 0; j < m; j++) {
            if (j != col && board[row][j] == num) return false;
        }

        
        int blockStartRow = (row / 3) * 3;
        int blockStartCol = (col / 3) * 3;
        for (int i = blockStartRow; i < blockStartRow + 3; i++) {
            for (int j = blockStartCol; j < blockStartCol + 3; j++) {
                if ((i != row || j != col) && board[i][j] == num) return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    if (!validate(i, j, board)) return false;
                }
            }
        }
        return true;
    }
};
