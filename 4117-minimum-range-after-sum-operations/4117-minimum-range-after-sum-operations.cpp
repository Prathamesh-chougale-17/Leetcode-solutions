class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int> t = {a,b,c};
        sort(t.begin(),t.end());
        if(t[2]>=(t[0]+t[1]))return t[1];
        return t[2]-t[0];
    }
};