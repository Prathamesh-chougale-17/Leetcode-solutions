class Solution {
public:
    string reverseStr(string s, int k) {
        // reverse(s.begin(),s.begin()+k);
        int n = s.size(),l=0;
        if(k>n) reverse(s.begin(),s.end());
        for(int i=0;i<n/k;i++){
            l=((k*2*i+k)>=n)?n:(k*2*i+k);
            reverse(s.begin()+k*2*i,s.begin()+l);
        }
        return s;
    }
};