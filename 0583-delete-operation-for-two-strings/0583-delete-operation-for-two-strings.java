class Solution {
    public int back(String a,String b,int i,int j,int[][] dp){
        if(i<0 || j<0)return Math.max(i,j)+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a.charAt(i)==b.charAt(j))return dp[i][j] = back(a,b,i-1,j-1,dp);
        return dp[i][j] = 1+Math.min(back(a,b,i-1,j,dp),back(a,b,i,j-1,dp));
    }
    public int minDistance(String a, String b) {
        int[][] dp = new int[a.length()][b.length()];
        for(int i=0;i<a.length();i++){
            Arrays.fill(dp[i],-1);
        }
        return back(a,b,a.length()-1,b.length()-1,dp);
    }
}