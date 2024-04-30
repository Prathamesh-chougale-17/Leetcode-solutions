class Solution {
public:
    bool check(vector<int>& nums) {
        int x = nums[0],y=nums[nums.size()-1],count{0};
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) count++;
        }
        if(count==1 && (x-y)>=0){
            return true;
        }
        else if(count==0) return true;
        return false;

    }
};