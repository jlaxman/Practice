class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    void push(int x) {
        int sz=q.size();
        q.push(x);
        while(sz--){
            int val=q.front();
            q.pop();
            q.push(val);
        }
        
    }
    
    int pop() {
        int v=q.front();
        q.pop();
        return v;
    }
    
    int top() {
       return q.front();
    }
    
    bool empty() {
        return !q.size();
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