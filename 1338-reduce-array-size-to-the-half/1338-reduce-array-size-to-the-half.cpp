class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int half = n/2;
        unordered_map<int,int> um;
        for(auto &i:arr){
            um[i]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        int k = 0;
        int mini = INT_MAX;
        for(auto &i:um){
            k+=i.second;
            pq.push(i.second);
            while(half<=k){
                int s = pq.size();
                mini = min(s,mini);
                k-=pq.top();
                pq.pop();
            }
        }
        return mini;
    }
};