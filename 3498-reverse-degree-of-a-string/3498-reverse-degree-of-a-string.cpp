class Solution {
public:
    int reverseDegree(string s) {
        int ans=0,n = s.size();
        for(int i=0;i<n;i++){
            int x = s[i] - 'a';
            ans+=((i+1)*(26-x));
        }
        return ans;
    }
};