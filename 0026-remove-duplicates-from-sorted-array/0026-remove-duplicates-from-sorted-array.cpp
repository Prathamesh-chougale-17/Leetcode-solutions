class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(auto &i:nums){
            s.insert(i);
        }
        int j=0;
        for(auto &i:s){
            nums[j]=i;
            j++;
        }
        return s.size();
    }
};