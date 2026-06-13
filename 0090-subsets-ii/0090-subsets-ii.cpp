using vvi = vector<vector<int>>;
using vi = vector<int>;
class Solution {
public:
    void back(vi &nums,vvi &ans,vi &sol,int i,int n){
        ans.push_back(sol);
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1])continue;
            sol.push_back(nums[j]);
            back(nums,ans,sol,j+1,n);
            sol.pop_back();
        }
    }
    vvi subsetsWithDup(vi& nums) {
        vvi ans;
        vi sol;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        back(nums,ans,sol,0,n);
        return ans;
    }
};