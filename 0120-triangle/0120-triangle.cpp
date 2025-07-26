class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        for(int i=1;i<n;i++){
            int m = t[i].size();
            for(int j = 0;j<m;j++){
                if(j==0) t[i][j]+=t[i-1][j];
                else if(j==(m-1)) t[i][j]+=t[i-1][j-1];
                else{
                    t[i][j] = min((t[i][j]+t[i-1][j-1]),(t[i][j]+t[i-1][j]));
                }
            }
        }
        return *min_element(t[n-1].begin(),t[n-1].end());
    }
};