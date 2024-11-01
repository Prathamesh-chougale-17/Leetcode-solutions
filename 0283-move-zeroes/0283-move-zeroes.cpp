class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 && nums[j-1]==0){
                swap(nums[j],nums[j-1]);
                j--;
            }
        }
    }
};