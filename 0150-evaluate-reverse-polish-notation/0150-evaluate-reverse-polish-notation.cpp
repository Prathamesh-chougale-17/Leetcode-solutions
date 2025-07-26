class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto &i:tokens){
            if(i=="*" || i=="-" || i=="+" || i=="/" ){
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                if(i=="*")st.push(to_string(num1*num2));
                if(i=="+")st.push(to_string(num1+num2));
                if(i=="/")st.push(to_string(num2/num1));
                if(i=="-")st.push(to_string(num2-num1));
            }else{
                st.push(i);
            }
            cout<<st.top()<<endl;
        }
        return stoi(st.top());
    }
};