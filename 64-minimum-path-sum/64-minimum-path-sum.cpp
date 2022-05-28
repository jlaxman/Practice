class Solution {
public:
     int fun(int i, int j, vector<vector<int>>& matrix , vector<vector<int>>& dp, int m, int n){
      if(i== m-1 && j==n-1 ){
          return matrix[m-1][n-1];
      }
      if(dp[i][j]!=-1) return dp[i][j];
       int op2=INT_MAX; int op3=INT_MAX;
      if(j+1<n){
          op2= matrix[i][j]+ fun(i, j+1, matrix, dp,m ,n);
      }
      if(i+1<m) op3= matrix[i][j]+ fun(i+1, j, matrix, dp,m, n);
      return dp[i][j]= min(op2, op3);
      
  }
public:
    int minPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(0, 0, matrix, dp, m, n);
        
    }
};