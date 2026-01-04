class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> temp = nums;
        for(int i=0;i<n;i++){
            nums[2*i]=temp[i];
            nums[2*i+1]=temp[n+i];
        }
        return nums;
    }
};