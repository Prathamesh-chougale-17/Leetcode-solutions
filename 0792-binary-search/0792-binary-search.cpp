class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int c = l + (r-l)/2;
            if(nums[c]==target){
                return c;
            }
            else if(nums[c]<target){
                l = c+1;
            } else {
                r = c-1;
            }
        }
        return -1;
    }
};