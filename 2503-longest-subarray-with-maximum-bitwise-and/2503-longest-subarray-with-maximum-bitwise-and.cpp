class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int sol=0,lenght=0;
        for(auto &i:nums)
            lenght = max(lenght,(maxi==i)?++sol:sol=0);
        return lenght;
    }
};