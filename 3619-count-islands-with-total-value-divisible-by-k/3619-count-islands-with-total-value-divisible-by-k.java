class Solution {
    public long dfs(int[][] g, int x,int y){
        if(x<0 || y<0 || x>=g.length || y>=g[0].length)return 0;
        if(g[x][y]==0)return 0;
        long org = g[x][y];
        g[x][y] = 0;
        long u = dfs(g,x-1,y);
        long d = dfs(g,x+1,y);
        long l = dfs(g,x,y-1);
        long r = dfs(g,x,y+1);
        // cout<< <<endl;
        return org + u + d + l + r;
    }
    public int countIslands(int[][] grid, int k) {
        int sol = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]!=0){
                    long s = dfs(grid,i,j);
                    if(s%k==0){
                        sol++;
                    }
                }
            }
        }
        return sol;
    }
}