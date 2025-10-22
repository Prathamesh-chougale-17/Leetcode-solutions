class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        else if(n==1)return x;
        else if(n==-1)return 1/x;
        else {
            double z = myPow(x,n/2);
            return z*z*myPow(x,n%2);
        }
    }
};