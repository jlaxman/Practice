class Solution {
    
    int fun(int i, vector<string>& s, vector<vector<vector<int>>>& dp, int N, int m, int n){
        if(i==N) return 0;
        
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        // not pick
        int op1= fun(i+1, s, dp, N, m, n);
        string s1= s[i];
        int z= count(s1.begin(), s1.end(), '0');
        int o= count(s1.begin(), s1.end(), '1');
        int op2=0;
        if(m-z>=0 && n-o>=0) op2= 1+ fun(i+1, s, dp, N, m-z, n-o);
        return dp[i][m][n]=max(op1, op2);
        
        
    }
public:
    int findMaxForm(vector<string>& s, int m, int n) {
        int N=s.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(m+1, vector<int>(n+1, -1)) );
        return fun(0, s, dp, N, m, n);
        
    }
};