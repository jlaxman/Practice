class Solution {
public:
    int fun(int i, vector<int>& coins, vector<vector<int>>& dp, int amt){
        if(amt<0) return 0;
        if(i==coins.size()){
            if(amt==0){
                return 1;
            }else return 0;
        }
        if(dp[i][amt]!=-1) return dp[i][amt];
        return dp[i][amt]=fun(i+1, coins, dp, amt)+ fun(i, coins, dp, amt-coins[i]);
    }
public:
    int change(int amt, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amt+1, -1));
        return fun(0, coins, dp, amt);
        
    }
};