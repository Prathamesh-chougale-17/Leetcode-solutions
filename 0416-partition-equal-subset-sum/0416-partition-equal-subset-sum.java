class Solution {
    public Boolean back(int[] nums,int i,int t,Boolean[][] dp){
        if(t==0)return true;
        if(i>=nums.length || t<0)return false;
        if(dp[i][t]!=null)return dp[i][t];
        return dp[i][t] = back(nums,i+1,t-nums[i],dp) || back(nums,i+1,t,dp);
    }
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2==1)return false;
        int target = (sum/2);
        Boolean[][] dp = new Boolean[nums.length][target+1];
        return back(nums,0,target,dp);
    }
}