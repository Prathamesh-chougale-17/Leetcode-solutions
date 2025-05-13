class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> c,r;
        int n = matrix[0].size(), m = matrix.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    c.insert(i);
                    r.insert(j);
                }
            }
        }
        for(auto &i:c){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
        for(auto &j:r){
            for(int i=0;i<m;i++){
                matrix[i][j]=0;
            }
        }
    }
};