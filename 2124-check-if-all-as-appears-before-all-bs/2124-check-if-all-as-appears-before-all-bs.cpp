class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        if(n==1)return true;
        for(int i=1;i<n;i++){
            if(s[i]-s[i-1]<0)return false;
        }
        return true;
    }
};