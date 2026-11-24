class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int x1 = c[0][1] , x2 = c[1][1];
        int y1 = c[0][0] , y2 = c[1][0];
        for(int i=2;i<c.size();i++){
            if((x2-x1)*(c[i][0]-y1)!=(y2-y1)*(c[i][1]-x1))return false;
        }
        return true;
    }
};