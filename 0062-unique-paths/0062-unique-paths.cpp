class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> up(m,vector<int> (n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                up[i][j] = up[i-1][j] + up[i][j-1];
            }
        }
        return up[m-1][n-1];
    }
};


// 0 1 1 1  1  1  1
// 1 2 3 4  5  6  7 
// 1 3 6 10 15 21 28