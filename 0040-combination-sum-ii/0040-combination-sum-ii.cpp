class Solution {
public:
    void back(vector<int>& c, int t,int i,int n,vector<vector<int>> &sol,vector<int> &ans){
        if(t==0){
            sol.push_back(ans);
            return;
        }
        if(t<0 || i==n)return;
        for(int j=i;j<n;j++){
            if(j>i && c[j]==c[j-1])continue;
            ans.push_back(c[j]);
            back(c,t-c[j],j+1,n,sol,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> sol;
        vector<int> ans;
        back(candidates,target,0,candidates.size(),sol,ans);
        return sol;
    }
};