// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{


	public:
	int fun(int i, int cost[], int n, int w, vector<vector<int>> & dp){
	    if(i==n){
	        if(w==0) return 0;
	        else return INT_MAX;
	    }
	    if(w==0) return 0;
	    if(w<0) return INT_MAX;
	    
	    if(dp[i][w]!=-1) return dp[i][w];
	    if(cost[i]==-1){
	        return dp[i][w]= fun(i+1, cost, n, w, dp);
	    }else{
	       int op1= fun(i+1, cost, n, w, dp);
	       int op2= fun(i, cost, n, w-(i+1), dp)==INT_MAX? INT_MAX: cost[i]+fun(i, cost, n, w-(i+1), dp);
	       return dp[i][w]=min(op1, op2);
	    }
	    
	    
	    
	    
	}

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        int n, w;
        n=N;
        w=W;
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        int ans=fun(0, cost, n, w, dp);
        if(ans==INT_MAX) return -1;
        else return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends