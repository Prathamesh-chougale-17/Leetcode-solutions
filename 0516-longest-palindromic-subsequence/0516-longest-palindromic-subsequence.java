class Solution {
    public int back(String s,int i,int j,int[][] dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s.charAt(i)==s.charAt(j) && j>i)return dp[i][j] = 2 + back(s,i+1,j-1,dp);
        if(s.charAt(i)==s.charAt(j) && j==i)return dp[i][j] = 1 + back(s,i+1,j-1,dp);
        return dp[i][j] = Math.max(back(s,i+1,j,dp),back(s,i,j-1,dp));
    }
    public int longestPalindromeSubseq(String s) {
        int[][] dp = new int[s.length()][s.length()];
        for(int i=0;i<s.length();i++){
            Arrays.fill(dp[i],-1);
        }
        return back(s,0,s.length()-1,dp);
    }
}