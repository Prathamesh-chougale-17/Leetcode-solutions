class Solution {
public:
    int minLength(string &s) {
        stack<char> st;
        char prev = '0';
        for(auto &i:s){
            if((prev=='A' && i=='B')||(prev=='C' && i=='D')){
                st.pop();
                prev = st.size()>0?st.top():'0';
            }
            else{
                st.push(i);
                prev=i;
            }
        }
        return st.size();
    }
};