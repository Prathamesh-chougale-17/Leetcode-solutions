class Solution {
public:
    bool isPowerOfTwo(int x) {
        if(x<1) return false;
        return x && !(x&(x-1));
    }
};