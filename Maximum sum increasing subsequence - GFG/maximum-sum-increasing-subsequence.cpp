// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		
int fun(int i, int a[], vector<int>& dp, int n){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        int mx=0;
        for(int k=i+1; k<n; k++){
            if(a[k]> a[i]){
                ans=a[k]+fun(k, a, dp, n);
                mx=max(ans, mx);
            }
        }
        return dp[i]=mx;
    }
	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n+1, -1);
	    int ans=0;
	    int mx=0;
	    for(int i=0; i<n; i++){
	      ans=a[i]+fun(i, a, dp, n);
	      mx=max(ans, mx);
	    }
	    return mx;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends