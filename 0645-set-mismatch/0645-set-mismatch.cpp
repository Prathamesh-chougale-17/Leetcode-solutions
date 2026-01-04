class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int missing = 1;
        int duplicate = 0;
        for(int i=0;i<nums.size();i++){
            if(missing==nums[i]){
                missing++;
            }
            if(i>0 && nums[i]==nums[i-1]){
                duplicate=nums[i];
            }
        }
        return {duplicate,missing};
    }
};