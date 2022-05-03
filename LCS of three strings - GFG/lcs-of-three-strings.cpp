// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int LCS(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp){
        if(i==s1.size() || j==s2.size() || k==s3.size()){
          return 0;  
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=0;
        if(s1[i]==s2[j] && s2[j]== s3[k]){
            ans=1+LCS(i+1, j+1, k+1, s1, s2, s3, dp);
            return dp[i][j][k]=ans;
        }else{
            int ans1= LCS(i+1, j, k, s1, s2, s3, dp);
            int ans2= LCS(i, j+1, k, s1, s2, s3, dp);
            int ans3= LCS(i, j, k+1, s1, s2, s3, dp);
            return dp[i][j][k]=max(ans1, max(ans2, ans3));
            
        }
        
    }
int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, -1)));
    int s=LCS(0, 0, 0, s1, s2, s3, dp);
    return s;
    
}
