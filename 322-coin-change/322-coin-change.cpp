class Solution {
    private: int dp[12][10007];
public:
    int fun(int i, vector<int>& coins, int k){
        if(k<0) return 1e7;
        if(i==coins.size() && k==0) return 0;
        if(i==coins.size() && k>0) return 1e7;
        if(dp[i][k]!=-1) return dp[i][k];
        int op1= 1+fun(i, coins, k-coins[i]);
        int op2= fun(i+1, coins, k);
       
        return  dp[i][k]=min(op1, op2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(), coins.end(), greater<int>());
        memset(dp, -1, sizeof dp);
        fun(0, coins, amount);
        return dp[0][amount]>=100000? -1:dp[0][amount] ;
    }
};