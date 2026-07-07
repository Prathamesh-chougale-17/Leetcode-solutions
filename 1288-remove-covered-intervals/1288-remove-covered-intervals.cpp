class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int start = intervals[0][0],end = intervals[0][1];
        int sol = 1;
        for(auto &i:intervals){
            if(i[0]>end || i[1]>end){
                sol++;
                start = i[0];end = i[1];
            }
        }

        return sol;
    }
};