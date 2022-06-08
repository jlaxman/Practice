class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int ans=0;
        while(pq.size()!=1){
           int x1= pq.top();
            pq.pop();
           int y1= pq.top();
            pq.pop();
            ans+=(x1+y1);
          pq.push(x1+y1);
        }
        return ans;
    }
};