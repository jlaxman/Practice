class Solution {
public:
    int dp[101][3];
    int minPrice(int i, int prev, vector<vector<int>>& costs){
        if(i==costs.size()){
            return 0;
        }
        if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];
        int ans=INT_MAX;
        int mini=INT_MAX;
        for(int k: {0,1,2}){
            if(prev!=k){
                ans=minPrice(i+1, k, costs)+costs[i][k];
            }
            mini=min(ans, mini);
        }
        if(prev==-1){
            return mini;
        }
        return dp[i][prev]=mini;
    }
    
public:
    int minCost(vector<vector<int>>& costs) {
        memset(dp, -1, sizeof dp);
        return minPrice(0, -1, costs);
    }
};