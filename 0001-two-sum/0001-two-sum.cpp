class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> um;
       int n = nums.size();
       for(int i=0;i<n;i++){
            if(um[nums[i]]>0) return {um[nums[i]]-1,i};
            um[target-nums[i]]=i+1;
       }
       return {-1};
    }
};