class Solution {
public:
    int maxAnswer(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i>=m || j>=n || i<0 || j<0 || !grid[i][j]) return 0;
        grid[i][j]=0;
        return  1+maxAnswer(i+1, j, m, n, grid)+ maxAnswer(i, j+1, m, n, grid)+maxAnswer(i-1, j, m, n, grid)+maxAnswer(i, j-1, m, n, grid);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    ans=max(ans, maxAnswer(i, j, m, n, grid));
                }
            }
        }
        return ans;
        
    }
};