class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int r=nums.size()-1,l=0,ans=nums.size(),mid=0;
        while(r>=l){
            mid=l+(r-l)/2;
            if(nums[mid]>=target){
                ans = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};