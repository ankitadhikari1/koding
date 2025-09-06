class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        vis[entrance[0]][entrance[1]] = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node.first.first;
            int col = node.first.second;
            int step = node.second;
            if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) &&
                !(row == entrance[0] && col == entrance[1]) &&
                maze[row][col] == '.') {
                return step;
            }

            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                int nx = row + dx[i];
                int ny = col + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
                    maze[nx][ny] != '+') {
                    vis[nx][ny] = 1;
                    q.push({{nx, ny}, step + 1});
                }
            }
        }

        return -1;
    }
};