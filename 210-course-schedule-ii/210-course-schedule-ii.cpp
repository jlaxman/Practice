class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);
    for(auto e: preq){
        adj[e[1]].push_back(e[0]);
        indegree[e[0]]++;
    }
    // priority_queue<int, vector<int>, greater<int> > q;
        queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int curr= q.front();
        q.pop();
        ans.push_back(curr);
        for(int nbr: adj[curr]){
            indegree[nbr]--;
            if(indegree[nbr]==0) q.push(nbr);
        }
        
    }
    if(ans.size()!=n) return {};
    return ans;
    
    }
};