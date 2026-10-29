class Solution {
    public int uniquePathsWithObstacles(int[][] o) {
        int n = o.length;
        int m = o[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                o[i][j]^=1;
            }
        }
        for(int i=1;i<n;i++){
            o[i][0]*=o[i-1][0];
        }
        for(int j=1;j<m;j++){
            o[0][j]*=o[0][j-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(o[i][j]==1)
                    o[i][j]=o[i-1][j]+o[i][j-1];
            }
        }

        return o[n-1][m-1];
        
    }
}