class MinStack {

public:
    // Solution: Just Track what the current min value is 
    // at any point in the stack. If you calculate and store the min
    // value every time you add then you will always now it!
    stack<pair<int, int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push({val, val});
        } else {
            int m = min(stk.top().second, val);
            stk.push({val, m});
        }
    }
    
    void pop() {
        if (!stk.empty()) {
            stk.pop(); // do not return value
        }
    }
    
    int top() {
        return stk.top().first; 
    }
    
    int getMin() {
        return stk.top().second;
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