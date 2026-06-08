class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(),l = n - 1;
        for(int i = l;i>=0;i--){
            if(nums[i]==val){
                cout<<i<<endl;
                swap(nums[i],nums[l]);
                l--;
            }
        }
        return l+1;        
    }
};