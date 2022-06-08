class FirstUnique {
public:
    unordered_map<int, int> mpp;
    queue<int> q;
    vector<int> vec;
    FirstUnique(vector<int>& nums) {
       for(auto n: nums){
           add(n);
       }
    }
    
    int showFirstUnique() {
      while(!q.empty() && mpp[q.front()]>1){
          q.pop();
      }
        if(q.empty()) return -1;
        else return q.front();
      
    }
    
    void add(int value) {
       mpp[value]++;
        q.push(value);
        
    }
    
    
    
    
    
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */