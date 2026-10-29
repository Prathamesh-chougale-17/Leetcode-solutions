class Solution {
    public int minFallingPathSum(int[][] m) {
        int n = m.length;
        int[][] dp = new int[n][n];
        for(int i=0;i<n;i++){
            dp[0][i] = m[0][i];
        }
        for(int i=1;i<n;i++){
            Arrays.fill(dp[i],Integer.MAX_VALUE);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=-1;k<2;k++){
                    if((j+k)>=0 && (j+k)<n){
                        dp[i][j] = Math.min(dp[i][j],m[i][j]+dp[i-1][k+j]);
                    }
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            min = Math.min(dp[n-1][i],min);
        }
        return min;
    }
}