class Solution {
public:
   int  minCost(int i, int j, int m, int n, string& s1, string& s2, vector<vector<int>>& dp){
        if(i==m){
            int ans=0;
            for(int k=j; k<n; k++){
                ans+=int(s2[k]);
            }
            return ans;
        }
       
       if(j==n){
            int ans=0;
            for(int k=i; k<m; k++){
                ans+=int(s1[k]);
            }
            return ans;
        }
       
       if(dp[i][j]!=-1) return dp[i][j];
       if(s1[i]==s2[j]){
           return dp[i][j]=minCost(i+1, j+1, m, n, s1, s2, dp);
       }else{
           return dp[i][j]=min(int(s1[i])+minCost(i+1, j, m, n, s1, s2, dp), int(s2[j])+minCost(i, j+1, m, n, s1, s2, dp));
       }
       
       
       
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minCost(0, 0, m, n, s1, s2, dp);
        
    }
};