// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    int fun(int n, int x, int y, int p, vector<vector<int>>& dp){
        if(n==0){
            if(p==0) return 0;
            return 1;
        }
        if(dp[n][p]!=-1) return dp[n][p];
        
        // if(n-x>=0){
        //     if(p==0){
        //         if(fun(n-x, x, y, 1-p, dp)==0) return dp[n][p]=1;
        //     }else{
        //         if(fun(n-x, x, y, 1-p, dp)==0) return dp[n][p]=1;
        //     }
        // }
        // if(n-y>=0){
        //     if(p==0){
        //         if(fun(n-y, x, y, 1-p, dp)==0) return dp[n][p]=1;
        //     }else{
        //         if(fun(n-y, x, y, 1-p, dp)==0) return dp[n][p]=1;
        //     }
        // }
       
        // if(p==0){
        //     if(fun(n-1, x, y, 1-p, dp)==0) return dp[n][p]=1;
        // }else{
        //     if(fun(n-1, x, y, 1-p, dp)==0) return dp[n][p]=1;
        // }
        
        for(int k: {x, y, 1}){
            if(n-k>=0){
                if(fun(n-k, x, y, p, dp)==0) return dp[n][p]=1;
            }
        }
        return dp[n][p]=0;
        
        
        
        
    }

	public:
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		vector<vector<int>> dp(N+1, vector<int>(2, -1));
		return fun(N, X, Y, 0, dp);
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends