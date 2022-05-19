class Solution {
    
int maxlength(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int n){
    
    if(dp[i][j]!=-1) return dp[i][j];
   
    int op1=0, op2=0, op3=0, op4=0;
    if(i+1<m && i+1>=0 && matrix[i+1][j]> matrix[i][j]) op1= maxlength(i+1, j, matrix, dp, m, n);
    if(j+1<n && j+1>=0 && matrix[i][j+1]> matrix[i][j]) op2= maxlength(i, j+1, matrix, dp, m, n);
    if(i-1<m && i-1>=0 && matrix[i-1][j]> matrix[i][j]) op3= maxlength(i-1, j, matrix, dp, m, n);
    if(j-1<n && j-1>=0 && matrix[i][j-1]> matrix[i][j]) op4= maxlength(i, j-1, matrix, dp, m, n);
    
    return dp[i][j]=1+ max(op1, max(op2, max(op3, op4)));
    
    
}
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxi=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]==-1){
                   maxi =max(maxi, maxlength(i, j, matrix, dp, m, n));
                }
            }
        }
        
        return maxi;
        
    }
};