class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(n==1) matrix[i][j]+=matrix[i-1][j];
                else if(j==0) matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j+1]);
                else if(j==(n-1)) matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j-1]);
                else{
                    matrix[i][j]+=min(matrix[i-1][j],min(matrix[i-1][j+1],matrix[i-1][j-1]));
                }
                cout<<matrix[i][j]<<"  ";
            }
            cout<<endl;
        }
        return *min_element(matrix[m-1].begin(),matrix[m-1].end());
    }
};