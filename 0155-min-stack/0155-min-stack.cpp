class MinStack {
public:
    vector<int>v;
    int mn = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.size()>0)mn = min(mn,val);
        else mn = val;
        v.push_back(val);
        v.push_back(mn);
    }
    
    void pop() {
        v.pop_back();
        v.pop_back();
        if(v.size()!=0)mn = v[v.size()-1];
    }
    
    int top() {
        return v[v.size()-2];
    }
    
    int getMin() {
        return v[v.size()-1];
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