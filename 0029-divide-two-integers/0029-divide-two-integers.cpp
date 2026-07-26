class Solution {
public:
    int min(int x,long long y){
        return x<y?x:y;
    }
    int divide(int dividend, int divisor) {
        int maxi = INT_MAX;
        return min(INT_MAX,1LL*dividend/divisor);
    }
};