class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        while(n){
            int x = n%10;
            pq.push(x);
            if(pq.size()>2)pq.pop();
            n = n/10;
        }
        int f = pq.top();pq.pop();
        return f * pq.top();
    }
};