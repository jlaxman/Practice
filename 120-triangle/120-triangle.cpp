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
        
        return tri[0][0]+minCost(0, 0, m, tri, dp);
        
    }
};