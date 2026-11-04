class Solution {
    public int back(int[] s,int i,int x,int t,int[][] dp){
        if(i==s.length) return Math.abs(t-2*x);
        if(dp[i][x]!=-1)return dp[i][x];
        int take = back(s,i+1,x+s[i],t,dp);
        int nottake = back(s,i+1,x,t,dp);
        return dp[i][x] = Math.min(take,nottake);
    }

    public int lastStoneWeightII(int[] s) {
        int t = 0;
        for(int i: s){
            t+=i;
        }
        int[][] dp = new int[s.length][t+1];
        for(int i=0;i<s.length;i++){
            Arrays.fill(dp[i],-1);
        }
        return back(s,0,0,t,dp);
    }
}

// 40 + 2 - 47