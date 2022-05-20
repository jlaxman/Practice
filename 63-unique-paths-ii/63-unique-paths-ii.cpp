class Solution {
    
    int fun(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n){
        if(i==m-1 && j==n-1) return 1;
        
        if(i>m-1 || j>n-1 || grid[i][j] ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int op1= fun(i+1, j, grid, dp, m, n);
        int op2= fun(i, j+1, grid, dp, m, n);
        return dp[i][j]=op1+op2;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
        if(grid[m-1][n-1]) return 0;
        return fun(0, 0, grid, dp, m, n);
        
    }
};