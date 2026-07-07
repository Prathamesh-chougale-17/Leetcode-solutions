class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sol=0;
        int sum = 0;
        int x = 0,z = 1;
        while(n){
            int k = n%10;
            if(k>0)
                x+=k*z;
            sum+=k%10;
            if(k>0)z*=10;
            n/=10;
        }
        sol = sum*1LL*x;
        return sol;
    }
};