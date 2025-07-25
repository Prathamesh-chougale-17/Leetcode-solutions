class Solution {
public:
    int maxi(vector<int> &nums,int n,int first,int last){
        vector<int> dp(n+1,0);
        dp[0]=nums[first];
        if(n==0) return dp[0];
        if(n>1)
            dp[1]=max(nums[first],nums[first+1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+nums[first+i],dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size(),last = 0;
        int first = maxi(nums,n-1,0,n-1);
        if(n>1)
            last = maxi(nums,n-1,1,n);
        return max(first,last);
        
    }
};