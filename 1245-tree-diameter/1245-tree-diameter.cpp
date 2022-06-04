class Solution {
    public:
    int dp[10002];
    int maxx;
    public:
    int maxDepth(int i, vector<vector<int>>& adj, int parent){
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        int mx=1;
        int ans1=0;
        int ans2=0;
       for(auto nbr: adj[i]){
           if(nbr!=parent) ans=1+maxDepth(nbr, adj, i);
           mx=max(ans, mx);
           
            int d=ans-1;;
            if(d>= ans1){
                ans2=ans1;
                ans1=d;
            }else{
                if(ans2<d){
                    ans2=d;
                }
            }
       }
        maxx= max(maxx, ans1+ans2);
        return dp[i]=mx;
    }
    
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        maxx=0;
        memset(dp, -1, sizeof dp);

        maxDepth(0, adj,-1);
        
        return maxx;
    }
};