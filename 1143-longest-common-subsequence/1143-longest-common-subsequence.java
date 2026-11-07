class Solution {
    public int back(String a,String b,int i,int j,int[][] dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a.charAt(i)==b.charAt(j))return dp[i][j] = 1 + back(a,b,i-1,j-1,dp);
        return dp[i][j] = Math.max(back(a,b,i-1,j,dp),back(a,b,i,j-1,dp));
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()][text2.length()];
        for(int i=0;i<text1.length();i++){
            Arrays.fill(dp[i],-1);
        }
        return back(text1,text2,text1.length()-1,text2.length()-1,dp);
    }
}