class Solution {
    public int back(int[] nums,int t,int i,int[][] dp){
        if(t==0)return 1;
        if(t<0 || i>=nums.length)return 0;
        if(dp[t][i]!=-1)return dp[t][i];
        int take =  back(nums,t-nums[i],0,dp);
        int notTake = back(nums,t,i+1,dp);
        return dp[t][i] = take + notTake;
    }
    public int combinationSum4(int[] nums, int target) {
        int[][] dp = new int[target+1][nums.length];
        for(int i=0;i<=target;i++){
            Arrays.fill(dp[i],-1);
        }
        return back(nums,target,0,dp);
    }
}