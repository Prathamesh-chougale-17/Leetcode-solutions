class Solution {
    public boolean isPre(String a,String b){
        if(a.length()+1!=b.length())return false;
        int j = 0;
        for(int i=0;i<b.length();i++){
            if(j<a.length() && b.charAt(i)==a.charAt(j)) j++;
        }
        return a.length()==j;
    }
    public int longestStrChain(String[] words) {
        int n = words.length,maxi = 1;
        int[] dp = new int[n];
        Arrays.fill(dp,1);
        Arrays.sort(words,(x,y)->x.length()-y.length());
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPre(words[j],words[i])){
                    dp[i] = Math.max(dp[i],1+dp[j]);
                }
            }
            maxi = Math.max(dp[i],maxi); 
        }
        return maxi;
    }
}