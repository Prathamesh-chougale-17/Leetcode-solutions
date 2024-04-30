class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i < (nums.size()) / 2; i++){
            if(nums[2 * i] != nums[2 * i + 1]) return nums[2 * i];
        }
        return nums[nums.size()-1];
    }
};