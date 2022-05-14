class Solution {
    
    
    void dfs(int s, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& vec, int n){
        if(s==n-1){
            vec.push_back(path);
            return ;
        }
        for(int nbr: graph[s]){
            path.push_back(nbr);
            dfs(nbr, graph, path, vec, n);
            path.pop_back();
        }
        return ;
        
        
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<vector<int>> vec;
        vector<int> path;
        path.push_back(0);
        dfs(0, graph, path, vec, n);
        return vec;
        
    }
};