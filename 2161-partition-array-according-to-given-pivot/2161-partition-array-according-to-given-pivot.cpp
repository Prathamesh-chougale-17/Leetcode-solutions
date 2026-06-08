class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l = 0, n=nums.size(),r = n-1;
        vector<int> res(n,pivot);
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)res[l++]=nums[i];
            if(nums[n-i-1]>pivot)res[r--]=nums[n-1-i];
        }
        return res;
    }
};