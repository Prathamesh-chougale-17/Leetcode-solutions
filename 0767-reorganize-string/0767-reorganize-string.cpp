class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> um;
        int n = s.size();
        int maxi = 0;
        for(auto &i:s){
            um[i]++;
            maxi = max(maxi,um[i]);
        }
        if(maxi>((n+1)/2))return "";
        int x = 0;
        priority_queue<pair<int,char>> pq;
        for(auto &i:um){
            pq.push({i.second,i.first});
        }
        while(!pq.empty()){
            char t = pq.top().second;
            int sz = pq.top().first;
            for(int i=0;i<sz;i++){
                s[x] = t;
                x+=2;
                if(x>=n)x=1;
            }
            pq.pop();
        }
        return s;
    }
};