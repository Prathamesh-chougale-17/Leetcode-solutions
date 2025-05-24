class Solution {
public:
    void comb(vector<int>& c,vector<int> &x,int t,int s,int i,int n,vector<vector<int>> &v){
        if(i==n || s>t){
            if(s==t)
                v.push_back(x);
            return;
        }
        comb(c,x,t,s,i+1,n,v);
        x.push_back(c[i]);
        comb(c,x,t,s+c[i],i,n,v);
        x.pop_back();
       
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> temp;
        comb(c,temp,t,0,0,c.size(),ans);
        return ans;
    }
};