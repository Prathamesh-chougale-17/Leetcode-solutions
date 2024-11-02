class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> um;
       int n = nums.size();
       for(int i=0;i<n;i++){
            if(um[target-nums[i]]==0 || target-nums[i]!=nums[i])
                um[target-nums[i]]=i+1;
            if(um[nums[i]]>0 && (um[nums[i]]-1)!=i) return {um[nums[i]]-1,i};
       }
       return {-1};
    }
};