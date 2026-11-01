class Solution {
    public int back(int[] p,int i,int b,int k,int[][][] dp){
        if(i>=p.length || k==0)return 0;
        if(dp[i][b][k]!=Integer.MIN_VALUE)return dp[i][b][k];
        int max = 0;
        if(b==1){
            max = Math.max(-p[i]+back(p,i+1,0,k,dp),back(p,i+1,1,k,dp));
        }else{
            max = Math.max(p[i]+back(p,i+1,1,k-1,dp),back(p,i+1,0,k,dp));
        }
        return dp[i][b][k] = max;
    }
    public int maxProfit(int k, int[] prices) {
        int[][][] dp = new int[prices.length][2][k+1];
        for(int i=0;i<prices.length;i++){
            for(int j=0;j<2;j++){
                Arrays.fill(dp[i][j],Integer.MIN_VALUE);
            }
        }
        return back(prices,0,1,k,dp);
    }
}