class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> vp;
        vector<int> ans;
        unordered_map<int,int> um;
        for(auto &i:nums) um[i]++;
        for(auto &i:um) vp.push_back(i);
        sort(vp.begin(),vp.end(),[](pair<int,int> &a,pair<int,int> &b){return a.second>b.second;});
        for(auto &i:vp){
            if(k>0){
                ans.push_back(i.first);
            }
            k--;
        }
        return ans;
    }
};
