class Solution {
    public int back(int[] coin,int a,int i,int[][] dp){
        if(a<0 || i<0)return 10001;
        if(a==0)return 0;
        if(dp[i][a]!=-1)return dp[i][a];
        int t = back(coin,a-coin[i],i,dp);
        int nt = back(coin,a,i-1,dp);
        return dp[i][a] = Math.min(1+t,nt);
    }
    public int coinChange(int[] coins, int amount) {
        int[][] dp = new int[coins.length][amount+1];
        for(int i=0;i<coins.length;i++){
            Arrays.fill(dp[i],-1);
        }
        int x = back(coins,amount,coins.length-1,dp);
        if(x>10000)return -1;
        return x;
    }
}