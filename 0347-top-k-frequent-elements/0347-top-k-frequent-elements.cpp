using pi = pair<int,int>;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(auto &i:nums){
            um[i]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto &i:um){
            pq.push({i.second,i.first});
            if(pq.size()>k)pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};