class Solution {
public:
    void back(int n,int i,vector<int> nums,vector<int> &s,vector<vector<int>> &ans){
        if(i==n){
            ans.push_back(s);
            return;
        }
        back(n,i+1,nums,s,ans);
        s.push_back(nums[i]);
        back(n,i+1,nums,s,ans);
        s.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        back(nums.size(),0,nums,s,ans);
        return ans;
    }
};