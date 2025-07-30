class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), c = 1,sumi = 1;
        int maxi = *max_element(nums.begin(),nums.end());
        if(n==1)return 1;
        for(int i=1;i<n;i++){
            if(nums[i]==maxi && nums[i]==nums[i-1]){
                c++;
                sumi = max(c,sumi);
            }else{
                c = 1;
            }
        }
        return sumi;
    }
};