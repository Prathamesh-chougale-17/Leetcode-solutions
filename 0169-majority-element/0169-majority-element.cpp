class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto &i:nums){
            m[i]++;
        }
        auto max = max_element(m.begin(),m.end(),[](pair<int,int> a,pair<int,int> b){return a.second<b.second;});
        return max->first;
    }
};