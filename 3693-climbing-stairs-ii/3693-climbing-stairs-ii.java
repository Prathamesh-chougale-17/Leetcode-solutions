class Solution {
    public int back(int[] cts,int i,int j,int[][] dp){
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = Integer.MAX_VALUE;
        for(int x = 1;x<=3;x++){
            mini = Math.min(mini,cts[i]+(x)*(x)+back(cts,i-x,x-1,dp));
        }
        // System.out.println(mini);
        return dp[i][j] = mini;
        
    }
    public int climbStairs(int n, int[] costs) {
        int[][] dp = new int[n][3];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return back(costs,n-1,0,dp);
    }
}