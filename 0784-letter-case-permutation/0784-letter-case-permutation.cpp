class Solution {
public:
    void back(vector<string> &ans,string &s,int i,int &n){
        if(i==n){
            ans.push_back(s);
            return;
        }
        back(ans,s,i+1,n);
        if(isalpha(s[i])){
            char x = s[i];
            s[i] = (x>='a' && x<='z') ? toupper(s[i]) : tolower(s[i]);
            back(ans,s,i+1,n);
            s[i] = x;
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.size();
        back(ans,s,0,n);
        return ans;
    }
};