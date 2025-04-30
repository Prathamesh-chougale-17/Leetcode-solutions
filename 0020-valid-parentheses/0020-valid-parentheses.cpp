class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto &i:s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }
            else if(st.size() && i==')' && st.top()=='(') st.pop();
            else if(st.size() && i=='}' && st.top()=='{') st.pop();
            else if(st.size() && i==']' && st.top()=='[') st.pop();
            else {
                return false;
                }
        }
        return !st.size();
    }
};