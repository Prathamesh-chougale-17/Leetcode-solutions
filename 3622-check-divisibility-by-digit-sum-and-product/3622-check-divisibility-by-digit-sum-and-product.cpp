class Solution {
public:
    bool checkDivisibility(int n) {
        int sm = 0,pd = 1;
        string nm = to_string(n);
        for(auto &i:nm){
            sm+=(i-'0');
            pd*=(i-'0');
        }
        return !(n%(sm+pd));
    }
};