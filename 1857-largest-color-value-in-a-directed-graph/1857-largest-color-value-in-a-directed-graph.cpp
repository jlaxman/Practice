class Solution {
 

public:
    int largestPathValue(string s, vector<vector<int>>& edges) {
        int n=s.size();
        if(edges.size()==0) return 1;
        vector<vector<int>> adj(n);
        vector<int> in(n, 0);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for(int i=0; i<n; i++){
            if(in[i]==0){
                q.push(i);
                dp[i][s[i]-'a']++;
            }
        }
        int mx=0;
        
        int seen=0;
        while(!q.empty()){
            int curr=q.front(); 
            q.pop();
            seen++;
            for(int nbr: adj[curr]){
                for(int i=0; i<26; i++){
                    dp[nbr][i]=max(dp[nbr][i], dp[curr][i]+(i==s[nbr]-'a'));
                    mx=max(mx, dp[nbr][i]);
                }
                in[nbr]--;
                if(in[nbr]==0){
                    q.push(nbr);
                }
            }
            
        }
        return seen<n? -1: mx;
        
        
        
    }
};