const long long MOD = 1000000007LL;

class Solution {
public:

    long long sol(long long n){
        if(n==0)return 1;
        if(n==1)return 20;
        long long a = sol(n/2) % MOD;
        long long b = sol(n%2) % MOD;
        return (a * a % MOD) * b % MOD;

    }
    int countGoodNumbers(long long n) {
        long long temp;
        temp = n%2?sol(n/2)*5:sol(n/2);
        return temp%MOD;
    }
};