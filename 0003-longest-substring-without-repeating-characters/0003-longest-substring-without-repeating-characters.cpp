class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int j=0,i=0,count{0},n = s.size();
        while(j<n){
            if(um.find(s[j])!=um.end()){
                i = max(um[s[j]]+1,i);
            }
            um[s[j]]=j;
            count = max(count,j-i+1);
            j++;
        }
        return count;
    }
};