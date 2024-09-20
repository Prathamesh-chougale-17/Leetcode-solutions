class Solution {
public:
    // bool ispali(const string &s) {
    //     int l = 0, r = s.size() - 1; // Fix the indexing here as well
    //     while (l < r) {
    //         if (s[l] != s[r]) return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }

    // string shortestPalindrome(string &s) {
    //     int size = s.size();
    //     string temp;
    //     for (int i = size-1; i >= 0; i--) {
    //         if (ispali(s.substr(0,i+1))) {
    //             if(i==size-1) return s;
    //             else{
    //                 temp = s.substr(i+1,size-i-1);
    //                 reverse(temp.begin(),temp.end());
    //                 return temp+s;
    //             }
    //         }
    //     }
    //     return s;
    // }

    int lps[100001];
    void preKmp(string& s){
        memset(lps, 0, sizeof(lps));
        int len=0;
        const int n=s.size();
        for(int i=1; i<n; i++){
            while(len>0 && s[i]!=s[len]) len=lps[len-1];
            lps[i]=(s[i]==s[len])? ++len: len;
        }
    }

    string shortestPalindrome(string& s) {
        string rev=string(s.rbegin(), s.rend());
        string pattern=s+'@'+rev;
        preKmp(pattern);
        int Len=lps[pattern.size()-1];
        return rev.substr(0, s.size()-Len)+s;   
    } 
};
