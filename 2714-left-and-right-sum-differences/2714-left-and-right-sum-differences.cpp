class Solution {
public:

    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum(nums.size(),0),rightsum(nums.size(),0),ans(nums.size(),0);
        int n = nums.size();
        for(int i=1;i<nums.size();i++){
            leftsum[i] = leftsum[i-1] + nums[i-1];
            rightsum[n-1-i] = rightsum[n-i] + nums[n-i];
        }
        for(int i=0;i<nums.size();i++){
            ans[i] = abs(leftsum[i]-rightsum[i]);
        }
        return ans;
    }
};