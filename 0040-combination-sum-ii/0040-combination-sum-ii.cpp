class Solution {
public:
    void back(vector<int>& c, int t,int i,int n,vector<vector<int>> &sol,vector<int> &ans){
        if(t==0){
            sol.push_back(ans);
            return;
        }
        if(t<0 || i==n)return;
        // if(i>0 && c[i]==c[i-1]){
        //     i++;
        //     return;
        // }
        ans.push_back(c[i]);
        back(c,t-c[i],i+1,n,sol,ans);
        ans.pop_back();
        int j = i + 1;
        while (j < n && c[j] == c[i]) j++;
        back(c,t,j,n,sol,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> sol;
        vector<int> ans;
        back(candidates,target,0,candidates.size(),sol,ans);
        return sol;
    }
};