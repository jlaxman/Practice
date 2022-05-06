class Solution {
public:
    int findCenter(vector<vector<int>>edges){
    vector<int> adj[edges.size()+2];
    for(auto e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        if(adj[e[0]].size()==edges.size()){
            return e[0];
        }
        if(adj[e[1]].size()==edges.size()){
            return e[1];
        }
    }
    return 0;
    
}
};