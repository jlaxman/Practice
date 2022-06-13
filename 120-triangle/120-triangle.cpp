class Solution {
public:
    int minCost(int i, int j, int m, vector<vector<int>>& tri, vector<vector<int>>& dp){
        if(i==m-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=min(tri[i+1][j]+minCost(i+1, j, m, tri, dp), tri[i+1][j+1]+minCost(i+1, j+1, m, tri, dp));
        
    }
    
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m= tri.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        for(int i=0; i<m; i++){
            dp[m-1][i]=0;
        }
        for(int i=m-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                dp[i][j]= min(tri[i+1][j]+dp[i+1][j], tri[i+1][j+1]+dp[i+1][j+1]);
            }
        }
        return tri[0][0]+dp[0][0];
        
      
    }
};