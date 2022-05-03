// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp(n+1, -1);
       int mx=0;
       for(int i=0; i<n; i++){
           mx=max(fun(i, a, dp, n), mx);
       }
       return mx+1;
    }
    int fun(int i, int a[], vector<int>& dp, int n){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        int mx=0;
        for(int k=i+1; k<n; k++){
            if(a[k]> a[i]){
                ans=1+fun(k, a, dp, n);
                mx=max(ans, mx);
            }
        }
        return dp[i]=mx;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends