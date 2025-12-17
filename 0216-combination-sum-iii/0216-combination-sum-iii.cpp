class Solution {
public:
    void back(int k,int n,int t,int i,vector<int> &ans,vector<vector<int>> &sol){
        if(k==0 && t==0){
            sol.push_back(ans);
            return;
        }
        if(k==0 || t<0){
            return;
        }
        for(int j=i;j<=9;j++){
            ans.push_back(j);
            back(k-1,n,t-j,j+1,ans,sol);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sol;
        vector<int> ans;
        back(k,n,n,1,ans,sol);
        return sol;
    }
};