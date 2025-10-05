class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,maxi=0,n=s.size();
        unordered_map<char,int> um;
        for(int i=0;i<n;i++){
            if(um.find(s[i])!=um.end()){
                l = max((um[s[i]]+1),l);
            }
            um[s[i]]=i;
            maxi=max((i-l+1),maxi);
        }
        return maxi;
    }
};