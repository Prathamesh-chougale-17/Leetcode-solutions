class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum{0},max{0},n=nums.size(),max_nega{INT_MIN};
        for(int i=0;i<n;i++){
            sum +=nums[i];
            if(sum<=0) {
                if(max_nega<nums[i]) max_nega=sum;
                sum=0;
            }
            else if(max<sum) max=sum;
        }
        if(max_nega<0 && max<=0) return max_nega;
        return max;
    }
};