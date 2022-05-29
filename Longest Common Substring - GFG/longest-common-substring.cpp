// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s, string s1, int n, int m)
    {
        // your code here
        int ans=0;
        int dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(s[i]==s1[j]){
                    dp[i][j]=1;
                    ans=max(dp[i][j], ans);
                }
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(dp[i][j]>0){
                    dp[i][j]+=dp[i-1][j-1];
                    ans=max(dp[i][j], ans);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends