class Solution {

    private int dfs(int x , int y , boolean[][]vis , int [][]grid){
        if(x<0 || x>=grid.length || y<0 || y>= grid[0].length){
            return 1;
        }
        if(vis[x][y]==true){
            return 0;
        }
        if(grid[x][y]==0){
            return 1;
        }

        vis[x][y] = true;

        return dfs(x+1,y,vis,grid) + dfs(x-1,y,vis,grid) + dfs(x,y+1,vis,grid) + dfs(x,y-1,vis,grid);
    }



    public int islandPerimeter(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean [][] vis = new boolean[n][m];
        int x =-1 , y= -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    x = i;
                    y = j;
                    break;
                }
            }
            if(x!=-1)break;
        }
        return dfs(x,y,vis,grid);
    }
}