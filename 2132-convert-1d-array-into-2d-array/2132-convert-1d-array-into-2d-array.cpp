class Solution {
public:
    bool isvalid(vector<int>& original, int m, int n){
        return original.size()==m*n?true:false;
    }
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(isvalid(original,m,n)){
            vector<vector<int>> v(m,vector<int> (n));
            for(int i=0;i<original.size();i++){
                v[i/n][i%n] = original[i];
            }
            return v;
        }
        return {};
    }
};