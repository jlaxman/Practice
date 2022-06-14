class MyQueue {
public:
    stack<int> st, rst;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
       if(rst.empty()){
           while(!st.empty()){
               rst.push(st.top());
               st.pop();
           }
           
       }
        int val=rst.top();
        rst.pop();
        return val;
            
    }
    
    int peek() {
        if(rst.empty()){
           while(!st.empty()){
               rst.push(st.top());
               st.pop();
           }
           
       }
        int val=rst.top();
        return val;
        
    }
    
    bool empty() {
       return !(st.size() || rst.size());
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