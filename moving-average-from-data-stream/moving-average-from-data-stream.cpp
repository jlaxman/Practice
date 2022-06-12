class MovingAverage {
public:
    queue<int> q;
    int sum;
    int sz;
    MovingAverage(int size) {
        sz=size;
        sum=0;
    }
    
    double next(int val) {
        if(q.size()>=sz){
            sum-=q.front();
            q.pop();
        }
        q.push(val);
        sum+=val;
        return ((1.0*sum)/(1.0*q.size()));
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */