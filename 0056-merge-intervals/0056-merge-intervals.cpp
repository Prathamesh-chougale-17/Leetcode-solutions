class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
        });
        vector<vector<int>> sol;
        
        int n = intervals.size();
        int x = intervals[0][0];
        int y = intervals[0][1];
        for(int i=0;i<n-1;i++){
            y = max(y,intervals[i][1]);
            if(y>=intervals[i+1][0]){
                x = min(x,intervals[i][0]);
            }else{
                sol.push_back({x,y});
                x = intervals[i+1][0];
            }
        }
        sol.push_back({x,max(y,intervals[n-1][1])});
        return sol;
    }
};