class Solution {

    private boolean isValid(int x, int y, char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1') {
            return false;
        }
        return true;
    }

    private void dfs(int x, int y, char[][] grid, boolean[][] vis) {
        vis[x][y] = true;

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (isValid(nx, ny, grid) && !vis[nx][ny]) {
                dfs(nx, ny, grid, vis);
            }
        }
    }

    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][] vis = new boolean[n][m];
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
}
