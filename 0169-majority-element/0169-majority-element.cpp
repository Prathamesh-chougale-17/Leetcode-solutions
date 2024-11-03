class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cani,count{0};
        for(auto &i:nums){
            if(count==0)cani = i;
            if(cani==i){
                count++;
            }
            if(cani!=i){
                count--;
            }
        }
        return cani;
    }
};