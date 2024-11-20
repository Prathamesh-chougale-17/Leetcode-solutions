class Solution {
public:
    int robHelper(vector<int> &nums, int n, vector<int> &dp) {
        if(n<=0){
            return 0;
        }
        if(dp[n-1]!=-1)return dp[n-1];
        int take = nums[n-1] + robHelper(nums,n-2,dp);
        int pass = robHelper(nums,n-1,dp);
        return dp[n-1]=max(take,pass);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // Memoization array initialized to -1.
        return robHelper(nums, n, dp);
    }
};