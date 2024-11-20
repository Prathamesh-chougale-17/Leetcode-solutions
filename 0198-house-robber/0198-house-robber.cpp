class Solution {
public:
    // int robHelper(vector<int> &nums, int n, vector<int> &dp) {
    //     if(n<=0){
    //         return 0;
    //     }
    //     if(dp[n-1]!=-1)return dp[n-1];
    //     int take = nums[n-1] + robHelper(nums,n-2,dp);
    //     int pass = robHelper(nums,n-1,dp);
    //     return dp[n-1]=max(take,pass);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        int prev = nums[0];
        if(n==0)return 0;
        if(n==1)return prev;
        int curr = max(nums[0],nums[1]);
        // Fill the dp array iteratively
        for (int i = 2; i < n; ++i) {
            int temp = max(nums[i] + prev, curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};