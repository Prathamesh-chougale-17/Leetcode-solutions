class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max{0},n{0};
        long long z{0};
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]) n++;
            else {
                if(max<n){
                    max=n;
                    z = nums[i-1];
                }
                n=1;
            }
        }
        if(max<n){
                    z = nums[nums.size()-1];
                }
                return z;
    }
};