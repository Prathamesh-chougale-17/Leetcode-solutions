class Solution {
public:
    // int sol(vector<int> &nums,int i,vector<int> &dp){
    //     if(i>=nums.size())return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     int l = sol(nums,i+2,dp);
    //     int r = sol(nums,i+3,dp);
    //     return dp[i] = max(l,r)+nums[i];
    // }
    // int back()
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1,-1);
        vector<int> dp(n+3);
        for(int i=n-1;i>=0;i--){
            dp[i] = max(dp[i+2],dp[i+3])+nums[i];
        }

        return max(dp[0],dp[1]);
        // return max(sol(nums,0,dp),sol(nums,1,dp));
    }
};