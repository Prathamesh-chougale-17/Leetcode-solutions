class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            if(um.contains(nums[i])){
                return {um[nums[i]],i};
            }
            um[target-nums[i]] = i;
        }
        return {0};
    }
};