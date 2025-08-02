class Solution {
public:
    int area(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = 0;
        queue<pair<int,int>> q;
        q.push({i,j});

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        int cnt = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = row + dx[k];
                int ny = col + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    cnt++;
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxCnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxCnt = max(maxCnt, area(i, j, grid));
                }
            }
        }

        return maxCnt;
    }
};
