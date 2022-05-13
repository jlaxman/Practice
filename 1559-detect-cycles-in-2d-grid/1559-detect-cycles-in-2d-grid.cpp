class Solution {
public:
    bool check(int x, int y, int m , int n){
        
        return (x>=0 && x<m && y>=0 && y<n);
    }
public:
    bool  dfs(int node, vector<vector<int >>& adj, vector<bool>& visited,  int parent){
        visited[node]=true;
        
        
        for(auto nbr: adj[node]){
            if(visited[nbr]==0){
                if(dfs(nbr, adj, visited, node)==true) return true;
            }else if( nbr!=parent){
                 return true;
            }
        }
    
        return false;
        
        
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dx[4]={0, 1, 0, -1};
        int dy[4]={1, 0, -1, 0};
        vector<bool> visited(m*n, false);
        
        vector<vector<int>> adj(m*n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                 for(int k=0; k<4; k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(check(x, y, m, n) && grid[x][y]==grid[i][j]){
                        adj[i*n+j].push_back(x*n+y);
                    }
                     
                 }
                
            }
            
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i*n+j]==false){
                   if( dfs(i*n+j, adj, visited, -1)) return true;
                }
            }
        }
        return false;
        
    }
};