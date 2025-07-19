class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,n = nums.size(),r = n-1;
        while(l<=r){
            int mid = (r+l)/2;
            cout<<l<<" "<<mid<<" "<<r<<endl;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                if(nums[r]>=nums[mid]){
                    r = mid - 1;
                }
                else {
                    if(nums[l]>target){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }
            }
            else{
                if(nums[l]<=nums[mid]){
                    l = mid + 1;
                }
                else{
                    if(nums[r]>=target){
                        l = mid + 1;
                    }else{
                    r = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};