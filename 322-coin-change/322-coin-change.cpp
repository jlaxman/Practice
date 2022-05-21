class Solution {
//     private: int dp[12][10007];
// public:
//     int fun(int i, vector<int>& coins, int k){
//         if(k<0) return 1e7;
//         if(i==coins.size() && k==0) return 0;
//         if(i==coins.size() && k>0) return 1e7;
//         if(dp[i][k]!=-1) return dp[i][k];
//         int op1= 1+fun(i, coins, k-coins[i]);
//         int op2= fun(i+1, coins, k);
       
//         return  dp[i][k]=min(op1, op2);
//     }
private: int memo[10004];

public:
    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof memo);
        return coinchange(coins, amount); 
    }
    int coinchange(vector<int>& coins, int amount) {
        
        //2D-DP with indices, k
        // sort(coins.begin(), coins.end(), greater<int>());
        // memset(dp, -1, sizeof dp);
        // fun(0, coins, amount);
        // return dp[0][amount]>=100000? -1:dp[0][amount] ;
        
        //1D-Memoisation
//         if(amount<0) return -1;
//         if(amount==0) return 0;
//         if(memo[amount]!=-1) return memo[amount];
//         int mincount=1e5;
//         for(int c: coins){
//             int ans= coinchange(coins, amount-c);
//             if(ans==-1) continue;
//             mincount= min(1+ans, mincount);
            
//         }
//         memo[amount]=mincount;
//         return  mincount==1e5?-1: mincount;
        
        //Bottom-up
        vector<int> Dp(10005, INT_MAX);
        Dp[0]=0;
        for(int i=1; i<=amount; i++){
            int mini=1e5;
            for(int c: coins){
                if(c<=i) mini= min(Dp[i-c], mini);
            }
            if(mini!=1e5) Dp[i]=1+mini;
            else Dp[i]=1e5;
            
        }
        return Dp[amount]==1e5?-1: Dp[amount];
        
    }
};