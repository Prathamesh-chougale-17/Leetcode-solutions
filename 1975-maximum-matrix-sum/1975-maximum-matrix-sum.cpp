class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sumi = 0;
        int neg = 0;
        int mini = INT_MAX;
        for(auto &i:matrix){
            for(auto &j:i){
                if(j<=0){
                    sumi-=j;
                    neg++;
                    mini = min(mini,-1*j);
                }else{
                    sumi+=j;
                    mini = min(mini,1*j);
                }
            }
        }
        if(neg%2){
            sumi-= (2*mini);
        }
        return sumi;
    }
};