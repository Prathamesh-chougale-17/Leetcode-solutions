class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto &i:nums){
            if(um[i]>0){
                return true;
            }
            um[i]++;
        }
        return false;
    }
};