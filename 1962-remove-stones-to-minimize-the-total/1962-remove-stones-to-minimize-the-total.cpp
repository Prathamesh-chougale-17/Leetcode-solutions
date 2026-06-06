class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sumi = 0;
        for(auto &i:piles){
            pq.push(i);
            sumi+=i;
        }
        while(k--){
            int x = pq.top();
            pq.pop();
            pq.push(x-x/2);
            sumi-=x/2;
        }
        return sumi;
    }
};