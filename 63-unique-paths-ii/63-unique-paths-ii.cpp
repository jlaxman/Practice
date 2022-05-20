class Solution {
    
//     int fun(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n){
//         if(i==m-1 && j==n-1) return 1;
        
//         if(i>m-1 || j>n-1 || grid[i][j] ) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int op1= fun(i+1, j, grid, dp, m, n);
//         int op2= fun(i, j+1, grid, dp, m, n);
//         return dp[i][j]=op1+op2;
//     }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        // if(grid[m-1][n-1]) return 0;
        // return fun(0, 0, grid, dp, m, n);
        if(grid[0][0]==0) dp[0][0]=1;
        for(int i=0; i<n; i++){
            if(grid[0][0]==0 && grid[0][i]==0){
                dp[0][i]=1;
            }else{
                break;
            }
        }
         for(int i=0; i<m; i++){
            if(grid[0][0]==0 && grid[i][0]==0 ){
                dp[i][0]=1;
            }else{
                break;
             }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(grid[i][j]==0){
                    dp[i][j]= dp[i-1][j]+ dp[i][j-1];
                }
            }
        }
        
        
        
        return dp[m-1][n-1];
        
        
    }
};