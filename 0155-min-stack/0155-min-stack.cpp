class MinStack {
public:
    stack<int> st,mst;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mst.push(val);
            return;
        }
        st.push(val);
        mst.push(min(mst.top(),val));
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
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