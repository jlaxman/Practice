class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][51];
    int recurse(int i, int j, int m, int n, int q){
        if(i>=m || i<0 || j>=n || j<0){
            return 1;
        }
        if(q<=0) return 0;
        if(dp[i][j][q]!=-1) return dp[i][j][q];
        int ans=0;
        int op1= recurse(i+1, j, m,  n, q-1);
        ans+= (op1%mod);
        ans%=mod;
        int op2= recurse(i-1, j,  m, n, q-1);
        ans+= (op2%mod);
        ans%=mod;
        int op3= recurse(i, j-1, m, n, q-1);
        ans+=(op3%mod);
        ans%=mod;
        int op4= recurse(i, j+1, m, n, q-1);
        ans+=(op4%mod);
        ans%=mod;
        return dp[i][j][q]= ans;
           
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        return recurse(startRow, startColumn, m, n, maxMove);
        
    }
};