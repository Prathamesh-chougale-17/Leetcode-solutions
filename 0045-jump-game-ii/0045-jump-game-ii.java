class Solution {
    public int back(int[] nums,int i,int[] dp){
        if((i+1)>=nums.length)return 0;
        if(dp[i]!=-1)return dp[i];
        int mini = (int)1e4+7;
        for(int x=1;x<=nums[i];x++){
            mini = Math.min(mini,1+back(nums,i+x,dp));
        }
        return dp[i] = mini;
    }
    public int jump(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp,-1);
        return back(nums,0,dp);
    }
}

// 2 4 3 4

// 2 4 2 4