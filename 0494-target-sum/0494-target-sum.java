class Solution {
    public int back(int[] nums,int t,int i,int[][] dp){
        if (i == nums.length) {
            return t == 0 ? 1 : 0;
        }
        if(dp[10000+t][i]!=Integer.MAX_VALUE)return dp[10000+t][i];
        return dp[10000+t][i] = back(nums,t+nums[i],i+1,dp) + back(nums,t-nums[i],i+1,dp);
    }
    public int findTargetSumWays(int[] nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        if (Math.abs(target) > totalSum || (target + totalSum) % 2 != 0) {
            return 0;
        }
        int INF = (int)1e5;
        int[][] dp = new int[INF][nums.length];
        for(int i=0;i<INF;i++){
            Arrays.fill(dp[i],Integer.MAX_VALUE);
        }
        return back(nums,target,0,dp);
    }
}