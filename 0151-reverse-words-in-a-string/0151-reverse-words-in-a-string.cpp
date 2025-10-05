class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        for(auto &i:s){
            if(i==' '){
                if(temp.size()){
                    st.push(temp);
                    temp = "";
                }
            }else{
                temp+=i;
            }
        }
        if(temp.size()){
            st.push(temp);
            temp="";
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
            if(st.size()>0){
                temp+=" ";
            }
        }
        return temp;
    }
};