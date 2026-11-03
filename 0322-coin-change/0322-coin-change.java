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
        int n = coins.length;
        int[][] dp = new int[coins.length][amount+1];
        // for(int i=0;i<coins.length;i++){
        //     Arrays.fill(dp[i],-1);
        // }
        // int x = back(coins,amount,coins.length-1,dp);
        // if(x>10000)return -1;
        // return x;
        int INF = (int)1e6;

        for(int i=0;i<coins.length;i++){
            Arrays.fill(dp[i],INF);
            dp[i][0] = 0;
        }

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int take = INF;
                if(j-coins[i]>=0)
                    take = dp[i][j-coins[i]];

                dp[i][j] = Math.min(1+take,dp[i-1][j]);
            }
        }
        return dp[coins.length-1][amount]==INF?-1:dp[coins.length-1][amount];
    }
}