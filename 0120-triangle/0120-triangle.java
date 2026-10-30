class Solution {
    // public int back(List<List<Integer>> t,int i,int j,int[][] dp){
    //     if(i>=t.size())return 0;
    //     if(dp[i][j]!=Integer.MIN_VALUE)return dp[i][j];
    //     return dp[i][j] = t.get(i).get(j) + Math.min(back(t,i+1,j,dp),back(t,i+1,j+1,dp));
    // }
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] dp = new int[n][n];
        // for(int i=0;i<n;i++){
        //     Arrays.fill(dp[i],Integer.MIN_VALUE);
        // }
        // int sol = back(triangle,0,0,dp);

        for(int i=0;i<n;i++){
            dp[n-1][i] = triangle.get(n-1).get(i);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle.get(i).size();j++){
                dp[i][j] = triangle.get(i).get(j) + Math.min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
}