class MinStack {
    int topi = -1;
    vector<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        topi++;
    }
    
    void pop() {
        if(topi>-1){
            st.pop_back();
            topi--;
        }
    }
    
    int top() {
        return st[topi];
    }
    
    int getMin() {
        if(topi==-1)return -1;
        return *min_element(st.begin(),st.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */