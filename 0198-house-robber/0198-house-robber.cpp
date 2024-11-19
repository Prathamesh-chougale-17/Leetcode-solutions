class Solution {
public:
    int robHelper(vector<int> &nums, int n, int curr, vector<int> &dp) {
        if (curr >= n) return 0; // Base case: No more houses to rob.
        if (dp[curr] != -1) return dp[curr]; // Use cached result.

        // Two choices: Rob current house or skip it.
        int rob = nums[curr] + robHelper(nums, n, curr + 2, dp); // Rob current, move to curr + 2.
        int skip = robHelper(nums, n, curr + 1, dp); // Skip current, move to curr + 1.

        dp[curr] = max(rob, skip); // Store and return the maximum profit.
        return dp[curr];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // Memoization array initialized to -1.
        return robHelper(nums, n, 0, dp); // Start from index 0.
    }
};