vector<int> dp(46,-1);
class Solution {
public:
    int climbStairs(int n) {
        // return n<3 ? n:climbStairs(n-1)+climbStairs(n-2);
        if(n<3) return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};