class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxi=0;
        for(auto &i:nums){
            if(i==1){
                count++;
            }
            else{
                count=0;
            }
            maxi = max(count,maxi);
        }
        return maxi;
    }
};