class Solution {

    public int getMaximumGold(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int maxGold = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    maxGold = Math.max(maxGold, dfs(grid, i, j));
                }
            }
        }

        return maxGold;
    }

    private int dfs(int[][] grid, int r, int c){
        int n = grid.length;
        int m = grid[0].length;

        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0)
            return 0;

        int gold = grid[r][c];

        grid[r][c] = 0;   

        int max = 0;

        max = Math.max(max, dfs(grid, r+1, c));
        max = Math.max(max, dfs(grid, r-1, c));
        max = Math.max(max, dfs(grid, r, c+1));
        max = Math.max(max, dfs(grid, r, c-1));

        grid[r][c] = gold;   

        return gold + max;
    }
}
