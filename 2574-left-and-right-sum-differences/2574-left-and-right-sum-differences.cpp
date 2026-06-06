class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1),suf(n+1),ans;
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i] + nums[i];
            suf[n-i-1]=suf[n-i] + nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            ans.push_back(abs(pre[i+1]-suf[i]));
        }
        return ans;
    }
};

/*
0  10 14 22 25
25 15 11  3  0
*/