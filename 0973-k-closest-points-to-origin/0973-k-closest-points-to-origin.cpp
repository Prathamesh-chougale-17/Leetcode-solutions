using pi = pair<int,vector<int>>;
using vvi = vector<vector<int>>;
class Solution {
public:
    vvi kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi> pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],points[i]});
            if(pq.size()>k)pq.pop();
        }
        vvi ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};