class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        long long sum=accumulate(target.begin(), target.end(), 0LL);
        if(target.size()==1) return target[0]==1;
        while(!pq.empty() && pq.top()!=1){
            long long curr=pq.top();
            long long z= sum-(curr);
            if(z==1) return 1;
            pq.pop();
            if((curr%z)==0 || (curr%z)==curr){
                return 0;
            }else{
                pq.push(curr%z);
                sum= (sum-curr)+(curr%z);
            }
            
        }
        return 1;
        
    }
};