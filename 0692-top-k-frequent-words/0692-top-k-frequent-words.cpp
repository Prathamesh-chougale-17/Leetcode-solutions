using piv = pair<int,string>;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto cmp = [](piv &a, piv &b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };
        unordered_map<string,int> um;
        priority_queue<piv,vector<piv>,decltype(cmp)> pq;
        for(auto &i:words){
            um[i]++;
        }
        for(auto &i:um){
            pq.push({i.second,i.first});
            if(pq.size()>k)pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};