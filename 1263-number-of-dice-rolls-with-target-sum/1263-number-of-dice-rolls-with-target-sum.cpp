class Solution {
    int mod = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(31,vector<int> (1001,-1));
        return sol(n,k,target,dp);
    }
    int sol(int n,int k,int t,vector<vector<int>> &dp){
        if (n == 0 && t == 0) return 1;
        if (n == 0 || t < 0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        long long count = 0;
        for (int i = 1; i <= k && i<=t; i++) {
            count = (count + sol(n - 1, k, t - i,dp)) % mod;
        }
        return dp[n][t] = count;
    }
};
