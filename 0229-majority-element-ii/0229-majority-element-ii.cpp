class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size();
        for(auto &i:nums){
            um[i]++;
        }
        vector<int> ans;
        for(auto &i:um){
            if(i.second>(n/3)){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};