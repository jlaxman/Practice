class Solution {
public:
    vector<int> neighbours(int n, vector<int>& ps ){
        vector<int> res;
        for(auto num: ps){
            res.push_back(n+num);
        }
        return res;
        
        
    }
public:
    int minSteps(int n, vector<int>& ps, int k,  vector<int>& dp){
        
        if(k==0) return 0;
        if(dp[k]!=-1) return dp[k];
        int ans=INT_MAX;
        int mini=INT_MAX;
        for(int j=0; j<n; j++){
            if(k>=ps[j]){
                ans= minSteps(n, ps, k-ps[j], dp);
                if(ans!=INT_MAX){
                    ans++;
                    mini=min(ans, mini);
                } 
            }else{
                break;
            }
        }
        return dp[k]=mini;
       
       
    }
public:
    int numSquares(int n) {
        vector<int> ps;
        queue<int> q;
        unordered_set<int> st;
        for(int i=1; i<=sqrt(n); i++){
            ps.push_back(i*i);
            q.push(i*i);
            st.insert(i*i);
            
        }
        
        int steps=1;
        while(!q.empty()){
            int sz=q.size();
            for(int k=0; k<sz; k++){
                int curr=q.front();
                q.pop();
                if(curr==n) return steps;
                for(auto nbr: neighbours(curr, ps)){
                    
                    if(st.find(nbr)==st.end() && nbr<=n){
                        st.insert(nbr);
                        q.push(nbr);
                    }
                } 
            }
            steps++;
            
            
        }
        return -1;
    
        
    }
};