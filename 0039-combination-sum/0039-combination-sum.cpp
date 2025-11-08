class Solution {
public:
    void back(vector<int> &c,int t,int i,int n,vector<vector<int>> &sol,vector<int> &ans){
        if(t==0){
            sol.push_back(ans);
            return;
        }
        if(i==n || t<0)return;
        for(int j=i;j<n;j++){
            ans.push_back(c[j]);
            back(c,t-c[j],j,n,sol,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> ans;
        back(candidates,target,0,candidates.size(),sol,ans);
        return sol;
    }
};