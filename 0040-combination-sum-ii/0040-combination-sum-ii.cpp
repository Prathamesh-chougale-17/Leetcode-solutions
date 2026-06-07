using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    void back(vi &c,vi &tmp,int t,vvi &sol,int &n,int i){
        if(t<=0){
            if(t==0)sol.push_back(tmp);
            return;
        }
        for(int j = i;j < n;j++){
            if(i<j && c[j]==c[j-1])continue;
            tmp.push_back(c[j]);
            back(c,tmp,t-c[j],sol,n,j+1);
            tmp.pop_back();
        }
    }
    vvi combinationSum2(vector<int>& c, int t) {
        vvi sol;
        vi tmp;
        int n = c.size();
        sort(c.begin(),c.end());
        back(c,tmp,t,sol,n,0);
        return sol;
    }
};