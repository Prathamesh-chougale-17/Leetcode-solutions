class Solution {
public:
    bool isPowerOfTwo(int x) {
        if(x<1) return false;
        return (x&(x-1))?false:true;
    }
};