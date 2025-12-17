class Solution {
public:
    void back(vector<int> &c,int n,int i,vector<int> &ans,vector<vector<int>> &sol){
        sol.push_back(ans);
        for(int j=i;j<n;j++){
            if(j>i && c[j-1]==c[j])continue;
            ans.push_back(c[j]);
            back(c,n,j+1,ans,sol);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        back(nums,nums.size(),0,ans,sol);
        return sol;
    }
};