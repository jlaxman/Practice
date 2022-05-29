class Solution {
    
public:
    bool check(int i, int j, int m, int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j]=1;
        int dx[4]={1, 0, -1, 0};
        int dy[4]={0, -1, 0, 1};
        int m=grid.size();
        int n=grid[0].size();
        
        for(int k: {0, 1, 2, 3}){
            int x= i+ dx[k];
            int y= j+ dy[k];
            if(check(x, y, m, n) && vis[x][y]==0 && grid[x][y]=='1'){
                dfs(x, y, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    dfs(i, j, vis, grid);
                }
                
            }
        }
        return cnt;
        
    }
};