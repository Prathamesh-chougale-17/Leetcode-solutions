class MyStack {
    int topi = -1;
    vector<int> st;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
        topi++;
    }
    
    int pop() {
        int nums = st[topi];
        if(topi>-1){
            st.pop_back();
            topi--;
        }
        return nums;
    }
    
    int top() {
        if(topi>-1)return st[topi];
        return -1;
    }
    
    bool empty() {
        return topi<0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */