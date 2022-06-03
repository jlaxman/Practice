class Solution {
public:
    bool check(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
    
    
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& heights, int m, int n){
        vis[i][j]=1;
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, 1, -1};
        for(int k: {0, 1, 2, 3}){
            int x=i+dx[k];
            int y=j+dy[k];
            if(check(x, y, m, n) && (vis[x][y]==0) && heights[x][y]>= heights[i][j]){
                dfs(x, y, vis, heights, m, n);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> vec;
        vector<vector<int>> avis(m, vector<int>(n, 0));
        vector<vector<int>> pvis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            dfs(i, 0, pvis, heights, m, n);
            dfs(i, n-1, avis, heights, m, n);
        }
        for(int i=0; i<n; i++){
            dfs(0, i, pvis, heights, m, n);
            dfs(m-1, i, avis, heights, m, n);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(avis[i][j] && pvis[i][j]){
                    vec.push_back({i, j});
                }
            }
        }
               
        return vec;
        
    }
};