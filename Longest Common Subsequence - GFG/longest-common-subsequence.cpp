// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x+1, vector<int>(y+1, -1));
        
        return LCS(0, 0, s1, s2, dp);
        
    }
    int LCS(int i, int j, string& s1, string& s2,  vector<vector<int>>& dp){
        if(i==s1.size() || j==s2.size()){
          return 0;  
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+LCS(i+1, j+1, s1, s2, dp);
            return dp[i][j]=ans;
        }else{
            int ans1= LCS(i+1, j, s1, s2, dp);
            int ans2= LCS(i, j+1, s1, s2, dp);
            return dp[i][j]=max(ans1, ans2);
            
        }
        
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends