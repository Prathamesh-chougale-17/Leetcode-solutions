class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        // return um[maxi];
        int sol=0,lenght=0;
        for(auto &i:nums){
          if(maxi==i){
            sol++;
            lenght=max(lenght,sol);
          }else{
            sol=0;
          }
        }
        return lenght;
    }
};