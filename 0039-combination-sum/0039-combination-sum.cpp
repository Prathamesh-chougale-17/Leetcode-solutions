using vvi = vector<vector<int>>;
using vi = vector<int>;
class Solution {
public:
    void back(vi &c,int t,vvi &ans,vi &sol,int i,int n){
        if(t==0)
            ans.push_back(sol);
        if(t<=0)return;
        for(int j = i;j<n;j++){
            sol.push_back(c[j]);
            back(c,t-c[j],ans,sol,j,n);
            sol.pop_back();
        }
    }
    vvi combinationSum(vi& c, int t) {
        vvi ans;
        vi sol;
        int n = c.size();
        int i = 0;
        back(c,t,ans,sol,i,n);
        return ans;
    }
};