class Solution {
    vector<int> prefix(vector<int>& nums){
        int n = nums.size();
        vector<int> res = nums;
        for(int i=1;i<n;i++) {
            res[i] += res[i-1];
        }
        return res;
    }
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = prefix(nums),sol(n);
        for(int i=0;i<n;i++){
            sol[i] = (pre[n-1]-pre[i])-nums[i]*(n-i-1) + nums[i]*(i+1) - pre[i];
        }
        return sol;
    }
};