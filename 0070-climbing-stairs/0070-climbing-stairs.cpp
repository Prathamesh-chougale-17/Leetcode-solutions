    vector<int> dp(46,0);
class Solution {
public:
    int climbStairs(int n) {
        if(n<2)return 1;
        if(dp[n]!=0)return dp[n];
        dp[n] = climbStairs(n-1)+climbStairs(n-2);
        return dp[n];
    }
};