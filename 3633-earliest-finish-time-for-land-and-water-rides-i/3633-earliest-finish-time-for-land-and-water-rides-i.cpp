class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int mini = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();
        for(int i=0;i<n;i++){
            int tl = landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                int wt = waterStartTime[j]+waterDuration[j];
                int twt = wt>landStartTime[i]?(wt+landDuration[i]):tl;
                int ttl = tl>waterStartTime[j]?(tl+waterDuration[j]):wt;
                mini = min(mini,min(twt,ttl));
            }
        }
        return mini;
    }
};