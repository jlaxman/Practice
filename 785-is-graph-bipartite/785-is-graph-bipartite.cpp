class Solution {

public:    
    bool dfs(int s, vector<vector<int>>& graph, vector<int>& visited, int color){
    visited[s]=color;
    for(int nbr: graph[s]){
        if(visited[nbr]==0){
            if(dfs(nbr, graph, visited, 3-color)==false) return false;
        }
        else if( visited[nbr]==color){
            return false;
        }
    }
    return true;
}   
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        
        for(int i=0; i<n; i++){
           if(visited[i]==0){
               if(dfs(i, graph, visited, 1)==false) return false;
           }
        }
        return true;
        
    }
};