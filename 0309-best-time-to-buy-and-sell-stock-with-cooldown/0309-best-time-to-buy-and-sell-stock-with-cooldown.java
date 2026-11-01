class Solution {
    public int back(int[] p,int i,int b,int[][] dp){
        if(i>=p.length)return 0;
        if(dp[i][b]!=Integer.MIN_VALUE) return dp[i][b];
        int max = 0;
        if(b==1){
            max = Math.max(-p[i]+back(p,i+1,0,dp),back(p,i+1,1,dp));
        }else{
            max = Math.max(p[i]+back(p,i+2,1,dp),back(p,i+1,0,dp));
        }
        return dp[i][b] = max;
    }
    public int maxProfit(int[] prices) {
        int[][] dp = new int[prices.length][2];
        for(int i=0;i<prices.length;i++){
            Arrays.fill(dp[i],Integer.MIN_VALUE);
        }
        return back(prices,0,1,dp);
    }
}