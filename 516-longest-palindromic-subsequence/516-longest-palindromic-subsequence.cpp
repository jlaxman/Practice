class Solution {
    
public:
    int fun(int i, int j, string& s, string& s1, int m, int n, vector<vector<int>>& dp){
        if(i==m || j==n){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s1[j]){
            return dp[i][j]=1+ fun(i+1, j+1, s, s1, m, n, dp);
        }else{
            return dp[i][j]=max(fun(i+1, j, s, s1, m, n, dp), fun(i, j+1, s, s1, m, n, dp));
        }
        
    }
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(), s1.end());
        int m=s.size();
        int n=s1.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return fun(0, 0, s, s1, m, n, dp);
    }
};