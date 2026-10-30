class Solution {
    public int back(int[][] m,int i,int j,int[][] dp){
        if(i>=m.length || j>=m[0].length)return 0;
        if(m[i][j]==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = 1 + Math.min(back(m,i+1,j,dp),Math.min(back(m,i+1,j+1,dp), back(m,i,j+1,dp)));
    }
    public int countSquares(int[][] matrix) {
        int sum = 0;
        int[][] dp = new int[matrix.length][matrix[0].length];
        for(int i=0;i<matrix.length;i++){
            Arrays.fill(dp[i],-1);
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                sum+=back(matrix,i,j,dp);
            }
        }
        return sum;
    }
}