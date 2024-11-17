class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(),longest=0;
        unordered_set<int> us(nums.begin(),nums.end());
        for(int &i:nums){
            if(us.find(i-1)==us.end()){
                int length = 1;
                while(us.find(i+length)!=us.end())length++;
                longest = max(longest,length);
            }
        }
        return longest;
    }
};