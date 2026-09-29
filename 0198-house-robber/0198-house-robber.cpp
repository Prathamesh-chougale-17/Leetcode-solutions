class Solution {
public:
    int sol(vector<int> &nums,int i,vector<int> &dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int l = sol(nums,i+2,dp);
        int r = sol(nums,i+3,dp);
        return dp[i] = max(l,r)+nums[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return max(sol(nums,0,dp),sol(nums,1,dp));
    }
};