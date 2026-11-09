class Solution {
    public void dfs(int[][] g,int i,int j){
        if(i<0 || j<0 || j>=g[0].length || i>=g.length || g[i][j]==0)return;
        g[i][j]=0;
        dfs(g,i-1,j);
        dfs(g,i+1,j);
        dfs(g,i,j+1);
        dfs(g,i,j-1);
    }
    public int numEnclaves(int[][] grid) {
        for(int i=0;i<grid.length;i++){
            dfs(grid,i,0);
            dfs(grid,i,grid[0].length-1);
        }
        for(int i=0;i<grid[0].length;i++){
            dfs(grid,0,i);
            dfs(grid,grid.length-1,i);
        }
        int sol = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                sol+=grid[i][j];
                // System.out.print(grid[i][j]+" ");
            }
            // System.out.println();
        }
        return sol;
    }
}