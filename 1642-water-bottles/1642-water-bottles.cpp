class Solution {
public:
    int numWaterBottles(int n, int k) {
        int  r{n},ans{n};
       while(r/k){
            ans+=r/k;
            r = r/k+r%k;
       }
       return ans;
    }
};