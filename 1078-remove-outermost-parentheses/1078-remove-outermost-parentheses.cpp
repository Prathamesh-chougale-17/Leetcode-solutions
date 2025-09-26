class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string sol;
        for(char &c:s){
            if(c=='('){
                st.push(c);
            }
            if(st.size()>1){
                sol+=c;
            }
            if(c==')'){
                st.pop();
            }
        }
        return sol;
    }
};