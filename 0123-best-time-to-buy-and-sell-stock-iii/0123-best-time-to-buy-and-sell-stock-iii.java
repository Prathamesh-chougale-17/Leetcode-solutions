class Solution {
    public int back(int[] p,int i,int isB,int d,int[][][] dp){
        if(i>=p.length || d==0)return 0;
        // if(d==0)return 
        if(dp[i][isB][d]!=Integer.MIN_VALUE)return dp[i][isB][d];
        int max = 0;
        if(isB==1){
            max =  Math.max(-p[i] + back(p,i+1,0,d,dp),back(p,i+1,1,d,dp));
        }else{
            max =  Math.max(p[i] + back(p,i+1,1,d-1,dp),back(p,i+1,0,d,dp));
        }
        return dp[i][isB][d] = max;
    }
    public int maxProfit(int[] prices) {
        int[][][] dp = new int[prices.length][2][3];
        for(int i=0;i<prices.length;i++){
            for(int j=0;j<2;j++){
                Arrays.fill(dp[i][j],Integer.MIN_VALUE);
            }
        }
        return back(prices,0,1,2,dp);
    }
}

// 1 2 -2 3 2 -5 2 5 -9
// 1 3 1 4 6 1 3 8 -1