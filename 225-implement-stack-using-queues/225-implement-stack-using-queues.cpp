class MyStack {
public:
    deque<int> dq;
    MyStack() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        int ans=dq.back();
        dq.pop_back();
        return ans;
    }
    
    int top() {
        return dq.back();
    }
    
    bool empty() {
        return !dq.size();
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