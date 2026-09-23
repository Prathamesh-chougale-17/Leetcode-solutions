class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0)return 0;
        int x = n-1;
        while(nums[x]==val){
            x--;
            if(x<0)return 0;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                swap(nums[i],nums[x]);
                while(nums[x]==val)x--;
            }
            if(i==x)return x+1;
        }
        return x+1;
    }
};