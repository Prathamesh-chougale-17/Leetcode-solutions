class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sol = 0;
        for(auto &i:nums){
            sol^=i;
        }
        return sol;
    }
};