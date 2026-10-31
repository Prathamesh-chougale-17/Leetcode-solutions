class Solution {
    public int back(int[][] g,int i,int j1,int j2,int[][][] dp){
        if(j1<0 || j1>=g[0].length || j2<0 || j2>=g[0].length){
            return 0;
        }
        if(i==g.length-1){
            if(j1==j2)return g[i][j1];
            else{
                return g[i][j1] + g[i][j2];
            }
        }
        
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];

        int max = 0;
        for(int k1 = -1;k1<2;k1++){
            for(int k2 = -1;k2<2;k2++){
                if(j1+k1>=0 && j1+k1<g[0].length && j2+k2>=0 && j2+k2<g[0].length){
                    max = Math.max(max,back(g,i+1,j1+k1,j2+k2,dp));
                }
            }
        }
        // if(j1==j2)return dp[i][j1][j2] = g[i][j1] + max;
        return dp[i][j1][j2] = ((j1==j2) ? g[i][j1] : g[i][j1]+g[i][j2])+ max;
    }
    public int cherryPickup(int[][] grid) {
        int n =grid.length,m = grid[0].length;
        int[][][] dp = new int[n][m][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }
        return back(grid,0,0,m-1,dp);
    }
}