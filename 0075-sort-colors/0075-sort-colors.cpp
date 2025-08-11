class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j=-1,k=-1,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j++;
                k++;
                if(k>j){
                    swap(nums[k],nums[i]);
                    swap(nums[k],nums[j]);
                }else swap(nums[i],nums[j]);
            }else if(nums[i]==1){
                k++;
                swap(nums[k],nums[i]);
            }
        }
    }
};