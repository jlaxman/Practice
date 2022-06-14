class Solution {
public:
    int LCS(int i, int j, int m, int n, string& s1, string& s2, vector<vector<int>>& dp){
        if(i==m || j==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+LCS(i+1, j+1, m, n, s1, s2, dp);
        }else{
            return dp[i][j]=max(LCS(i+1, j, m, n, s1, s2, dp), LCS(i, j+1, m, n, s1, s2, dp));
        } 
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return LCS(0, 0, text1.size(), text2.size(), text1, text2, dp);
    }
};