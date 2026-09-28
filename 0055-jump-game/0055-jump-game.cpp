class Solution {
public:
    bool canJump(vector<int>& nums) {
        int x = 0;
        int n =nums.size();
        for(int i=0;i<n;i++){
            if(i>x)return false;
            if(i>=n)return true;
            x = max(x,i+nums[i]);
        }
        return true;
    }
};