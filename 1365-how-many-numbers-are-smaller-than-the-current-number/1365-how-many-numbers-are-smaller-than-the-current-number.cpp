class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums,ans;
        sort(temp.begin(),temp.end());
        for(auto &i:nums){
            int n = lower_bound(temp.begin(),temp.end(),i) - temp.begin();
            ans.push_back(n);
        }
        return ans;
    }
};