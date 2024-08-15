class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lans = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        nums.push_back(-1);
        if(nums[lans]!=target) return {-1,-1};
        nums.pop_back();
        return {lans,(int)(upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1)};
    }
};