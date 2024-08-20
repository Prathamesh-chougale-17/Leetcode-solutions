class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<right){
            if(!isalnum(s[left])){
                cout<<s[left];
                left++;
            }
            if(!isalnum(s[right])){
                right--;
            }
            if(isalnum(s[right]) && isalnum(s[left])){
                if(tolower(s[left])!=tolower(s[right])) {
                cout<<s[left]<<" "<<s[right]<<endl;
                return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};
