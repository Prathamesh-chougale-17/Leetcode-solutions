class Solution {
public:
    int back(vector<int> &nums,int i,vector<int> &dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i] = nums[i]+max(back(nums,i+2,dp),back(nums,i+3,dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return max(back(nums,0,dp),back(nums,1,dp));
    }
};