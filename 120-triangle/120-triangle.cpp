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
        vector<int> dp(m, -1);
        
        for(int i=0; i<m; i++){
            dp[i]=0;
        }
        for(int i=m-2; i>=0; i--){
            vector<int> curr(m, 0);
            for(int j=i; j>=0; j--){
                curr[j]= min(tri[i+1][j]+dp[j], tri[i+1][j+1]+dp[j+1]);
            }
            dp=curr;
        }
        return tri[0][0]+dp[0];
        
      
    }
};