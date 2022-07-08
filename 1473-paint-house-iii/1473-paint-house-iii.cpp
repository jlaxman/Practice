class Solution {
public:
    int dp[101][21][101];
    int minPrice(int i, int prev, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target ){
        if(target<0) return INT_MAX;
        if(i==m){
            if(target==0){
                return 0;
            }else{
                return INT_MAX;
            }
        }
        int ans=INT_MAX;
        int nxtans=INT_MAX;
        if(houses[i]!=0){
            if(prev==houses[i]){
                nxtans=minPrice(i+1, prev, houses, cost, m, n, target);
            }else{
                   nxtans=minPrice(i+1, houses[i], houses, cost, m, n, target-1);
            }
            if(prev==-1) return nxtans;
            return dp[i][prev][target]=nxtans;
        }
        if(prev!=-1 && dp[i][prev][target]!=-1) return dp[i][prev][target];
        
        for(int j=0; j<n; j++){
            if(prev!=j+1){
                nxtans= minPrice(i+1, j+1, houses, cost, m, n, target-1);
            }
            else {
                 nxtans= minPrice(i+1, prev, houses, cost, m, n, target);
            }
            if(nxtans!=INT_MAX){
                ans=min(cost[i][j]+nxtans, ans);
            }
        }
        if(prev==-1){
            return ans;
        }
        return dp[i][prev][target]=ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof dp);
        int ans=minPrice(0, -1, houses, cost, m, n, target);
        if(ans==INT_MAX) return -1;
        else return ans;
        
    }
};