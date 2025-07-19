class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if(r == 0)return nums[r];
        while(l<r){
            int mid = l +(r-l)/2;
            cout<<l<<" "<<mid<<" "<<r<<endl;
            if(nums[mid]==nums[mid+1]){
                if((mid-l)%2){
                    r = mid - 1;
                }
                else{
                    l = mid + 2;
                }
            }
            else if(nums[mid] == nums[mid-1]){
                if((mid-l)%2){
                    l = mid + 1;
                }
                else{
                    r = mid - 2;
                }
            } else{
                return nums[mid];
            }
        }
        return nums[l];
    }
};