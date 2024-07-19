class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;     
        for(int i =0;i<m;i++){
            int temp=INT_MAX,maxi=0,ind=0;
            for(int j=0;j<n;j++){
                // temp = min(temp,matrix[i][j]);
                if(temp>matrix[i][j]){
                    temp = matrix[i][j];
                    ind = j;
                }
            }
            for(int j=0;j<m;j++){
                maxi = max(maxi,matrix[j][ind]);
            }
            if(maxi==temp) ans.push_back(maxi);
        }
        return ans;
    }
};