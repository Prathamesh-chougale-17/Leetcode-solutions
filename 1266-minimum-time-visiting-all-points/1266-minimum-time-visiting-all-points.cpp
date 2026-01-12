class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0, n = points.size(),x=0,y=0;
        if(n>1){
            for(int i=1;i<n;i++){
                x=abs(points[i][0]-points[i-1][0]);
                y=abs(points[i][1]-points[i-1][1]);
                time+=max(x,y);
                y=0;x=0;
            }
        }
        return time;
    }
};