using pi = pair<int,int>;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k)pq.pop();
        }
        vector<int> ans;
        priority_queue<pi,vector<pi>,greater<pi>> aq;
        for(int i=0;i<k;i++){
            aq.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        while(!aq.empty()){
            ans.push_back(aq.top().second);
            aq.pop();
        }
        return ans;
    }
};