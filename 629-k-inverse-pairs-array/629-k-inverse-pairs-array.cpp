class Solution {
public:
    int dp[1001][1001];
    int mod=1e9+7;
//     int kinversePairs(int n, int k){
//         if(n==0) return 0;
//         if(k==0) return 1;
//         if(dp[n][k]!=-1){
//             return dp[n][k];
//         }
//         int ans=0;
//         for(int i=0; i<=min(k, n-1); i++){
//             ans= (ans%mod+(kinversePairs(n-1, k-i)%mod))%mod;
//             ans%=mod;
//         }
//         return dp[n][k]=ans;
        
//     }
    int kInversePairs(int n, int k) {
        memset(dp, 0, sizeof dp);
        for(int i=0; i<=k; i++){
            dp[0][i]=0;
        }
        for(int i=1; i<=n; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<=n; i++){
            
            for(int m=1; m<=k; m++){
                
                
                
                 int val = (dp[i - 1][m] + mod- ((m - i) >= 0 ? dp[i - 1][m - i] : 0)) % mod;
                    dp[i][m] = (dp[i][m - 1] + val) % mod;
            }
            
        }
        
        
       return ((dp[n][k] + mod - (k > 0 ? dp[n][k - 1] : 0)) % mod);
    }
};