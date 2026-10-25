class Solution {
    public void dfs(int[][] grid,int x,int y){
        if(x<0 || x>=grid.length || y<0 || y>=grid[0].length){
            return;
        }

        if(grid[x][y]==1){
            return;
        }

        grid[x][y] = 1;

        dfs(grid,x+1,y);
        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
    }
    public int closedIsland(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                dfs(grid,i,0);
            }
            if(grid[i][m-1]==0){
                dfs(grid,i,m-1);
            }
        }

        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                dfs(grid,0,i);
            }
            if(grid[n-1][i]==0){
                dfs(grid,n-1,i);
            }
        }
        int sol=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    System.out.println(i+" "+j);
                    sol++;
                    dfs(grid,i,j);
                }
            }
        }
        return sol;
    }
}