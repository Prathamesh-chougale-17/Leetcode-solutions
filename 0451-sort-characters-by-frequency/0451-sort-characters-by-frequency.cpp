class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> um;
        for(auto &i:s){
            um[i]++;
        }
        priority_queue<pair<int,char>> maxh;
        for(auto &i:um){
            maxh.push({i.second,i.first});
        }
        string ans;
        while(!maxh.empty()){
            int n = maxh.top().first;
            char c = maxh.top().second;
            for(int i=0;i<n;i++){
                ans.push_back(c);
            }
            maxh.pop();
        }
        return ans;
    }
};