class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int,int> um;
        int product=1;
        for(auto &i:nums){
            ++um[i];
            if(i!=0)
                product*=i;
            if(um[0]>1){
                product = 0;
                break;
            }
        }
        if(um[0]>0)for(auto &i:nums) i = i==0 ? product:0;
        else for(auto &i:nums) i = product/i;
        return nums;
    }
};
