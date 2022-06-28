class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto ch: s){
            freq[ch-'a']++;
        }
        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            if(freq[i]){
                pq.push(freq[i]);
            }
        }
        int ans=0;
        while(!pq.empty()){
            
            int val=pq.top();
            pq.pop();
            while(!pq.empty() && pq.top()==val){
                pq.pop();
                if(val-1) pq.push(val-1);
                ans++;
            }
     
        }
        return ans;
        
       
       
        
    }
};