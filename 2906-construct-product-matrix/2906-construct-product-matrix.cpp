class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        vector<int> temp,pre(n*m),suf(n*m),so(n*m);
        vector<vector<int>> sol(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }
        pre[0]=temp[0]%mod;suf[n*m-1]=temp[n*m-1]%mod;
        for(int i=1;i<n*m;i++){
            pre[i]=((pre[i-1]%mod)*(temp[i]%mod))%mod;
            suf[n*m-1-i]=((suf[n*m-i]%mod)*(temp[n*m-1-i]%mod))%mod;
        }
        so[0]=suf[1]%mod;so[n*m-1]=pre[n*m-2]%mod;
        for(int i=1;i<n*m-1;i++){
            so[i]=((pre[i-1]%mod)*(suf[i+1]%mod))%mod;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sol[i][j]=so[i*m+j];
            }
        }
        return sol;
    }
};