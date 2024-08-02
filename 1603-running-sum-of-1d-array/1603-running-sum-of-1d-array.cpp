class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // vector<int> ans = nums;
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};