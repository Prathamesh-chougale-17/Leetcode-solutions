class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n){
            ans+=1&(n);
            n = n>>1;
        }
        return ans;
    }
};