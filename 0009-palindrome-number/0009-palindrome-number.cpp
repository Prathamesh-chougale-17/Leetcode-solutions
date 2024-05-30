class Solution {
public:
    int numrev(int x){
        long rev{0};
        while(x){
            rev = rev*10 + x%10;
            x/=10;
        }
        if(rev>INT_MAX || rev<INT_MIN) return 0;
        return rev;
    }
    bool isPalindrome(int x) {
        // int n = 
        // for(int i=0;i<)
        int y = numrev(x);
        if(y==x && x>=0) return true;
        return false;
    }
};