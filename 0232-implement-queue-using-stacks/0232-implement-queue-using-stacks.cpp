class MyQueue {
public:
    stack<int>st;
    stack<int>st1;
    MyQueue() {
        
    }
    
    void push(int x) {
       while(!st.empty()) {
            st1.push(st.top());
            st.pop();
        }
        st1.push(x);
        while(!st1.empty()) {
            st.push(st1.top());
            st1.pop();
        }
    }
    
    int pop() {
        int x=st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */