class Solution {
public:
    void back(int &sol,int x,int y,int m,int n){
        if(x==(n-1) && y==(m-1)){
            sol++;
            return;
        }
        if(x<n-1){
            back(sol,x+1,y,m,n);
        }
        if(y<m-1){    
            back(sol,x,y+1,m,n);
        }
    }
    int uniquePaths(int m, int n) {
        long long up = 1,down = 1;
        int sol = 0;

        // back(sol,0,0,m-1,n-1);
        // if(m>n) return uniquePaths(n,m);
        // for(int i=0;i<m-1;i++){
        //     up *= 1LL * (n + m - 2  - i);
        //     down *= 1LL * (i+1);
        // }
        // return up/down;
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }

        return dp[m-1][n-1];
    }
};