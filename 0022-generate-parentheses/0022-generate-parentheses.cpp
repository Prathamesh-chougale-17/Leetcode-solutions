class Solution {
    vector<string> valid;
public:
    void generate(int open,int close,string &s){
        if(close==0 && open==0){
            valid.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            generate(open-1,close,s);
            s.pop_back();
        }
        if(close>0 && open<close){
            s.push_back(')');
            generate(open,close-1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        generate(n,n,s);
        return valid;
    }
};