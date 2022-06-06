class Solution {
private:
    int dp[1002][2][101];
    int getmaxProfit(int i, int j, int k, vector<int>& prices){
        if(i==prices.size()) return 0;
        if(k==0) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        if(j==0){
            return dp[i][j][k]=max(getmaxProfit(i+1, j, k, prices) , getmaxProfit(i+1, 1, k, prices)-prices[i]);
        }else{
             return dp[i][j][k]=max(getmaxProfit(i+1, j, k, prices) , getmaxProfit(i+1, 0, k-1, prices)+prices[i]);
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return getmaxProfit(0, 0, k, prices);
    }
};