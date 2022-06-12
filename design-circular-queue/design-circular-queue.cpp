class MyCircularQueue {
public:
    vector<int> q;
    int head, tail;
    int cnt;
    MyCircularQueue(int k) {
        q.resize(k, 0);
         head=0;
         tail=0;
         cnt=0;
    }
    
    bool enQueue(int value) {
       if(cnt==q.size()){
           return 0;
       }else{
           q[tail]=value;
           tail++;
           if(tail==q.size()){
               tail=0;
           }
           cnt++;
           return 1;
       }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return 0;
        }else{
            head++;
            if(head==q.size()){
                head=0;
            }
            cnt--;
            return 1;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }else{
            return q[head];
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }else{
            if(tail==0){
                return q[q.size()-1];
                
            }else{
                return q[tail-1];
            }
        }
    }
    
    bool isEmpty() {
        return !cnt;
    }
    
    bool isFull() {
        return cnt==q.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */