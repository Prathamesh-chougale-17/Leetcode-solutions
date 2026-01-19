class Solution {
public:
    long long mult(long long n,int mod){
        if(n==0)return 1;
        if(n==1)return 20;
        long long x = mult(n/2,mod)%mod;
        if(n%2){
            return ((20 *1LL* x%mod * x%mod) %mod)%mod;
        }
        return ((x%mod*1LL*x%mod)%mod)%mod;
    }
    int countGoodNumbers(long long n) {
        int mod = 1e9+7;
        long long int muli = 1;
        if(n%2){
            muli=(mult(n/2,mod)*5)% mod;
        }else{
            muli=mult(n/2,mod);
        }
        return muli==1?0:muli;
    }
};