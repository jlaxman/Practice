class Solution {
private:
    int dp[101][101][202];
public:
     int checkInterleave(int i, int j, int k, int l, int m, int n, string &s1, string &s2, string &s3){
         if(k==n){
             return 1;
         }
         if(dp[i][j][k]!=-1) return dp[i][j][k];
         if(i< l && j< m && s1[i]==s2[j] && s2[j]==s3[k]){
             return dp[i][j][k]=(checkInterleave(i+1, j, k+1, l, m, n, s1, s2, s3) || checkInterleave(i, j+1, k+1, l, m, n, s1, s2, s3));
         }else if(i<l && s1[i]==s3[k]){
             return dp[i][j][k]=checkInterleave(i+1, j, k+1, l, m, n, s1, s2, s3);
         }else if(j<m && s2[j]==s3[k]){
             return dp[i][j][k]=checkInterleave(i, j+1, k+1, l, m, n, s1, s2, s3);
         }
             
         if(i<l &&  j<m) return dp[i][j][k]=checkInterleave(i+1, j+1, k, l, m, n, s1, s2, s3);
         
         return dp[i][j][k]=0;
        
     } 
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l=s1.size();
        int m=s2.size();
        int n=s3.size();
        if(n!=l+m) return 0;
        memset(dp, -1, sizeof dp);
      return checkInterleave(0, 0, 0, l, m, n, s1, s2, s3); 
    }
};