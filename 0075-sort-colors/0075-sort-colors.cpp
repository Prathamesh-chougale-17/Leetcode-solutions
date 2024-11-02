class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j=0,k=0,n=nums.size();
        for(int i=0;i<n;i++){
            int temp = nums[i];
            // cout<<j<<k<<endl;
            if(j<i && nums[j]>nums[i])
                swap(nums[i],nums[j]);
            if(k!=j && k<i)
                swap(nums[k],nums[i]);
            if(temp<1) j++;
            if(temp<2) k++;
        }
    }
};