class Solution {
public:

    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n,0),rightsum(n,0),ans(n,0);
        for(int i=1;i<n;i++){
            leftsum[i] = leftsum[i-1] + nums[i-1];
            rightsum[n-1-i] = rightsum[n-i] + nums[n-i];
        }
        for(int i=0;i<n;i++){
            ans[i] = abs(leftsum[i]-rightsum[i]);
        }
        return ans;
    }
};