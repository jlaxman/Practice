// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    int dp[1001][1001];
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp, -1, sizeof dp);
       return ks(0, val, wt, W, n);
    }
    int ks(int i, int val[], int wt[], int W, int n){
        if(W<0) return INT_MIN;
        if(i==n){
            if(W<0) return INT_MIN;
            else return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int op1= val[i]+ks(i+1, val, wt, W-wt[i], n);
        int op2= ks(i+1, val, wt, W, n);
        return dp[i][W]=max(op1, op2);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends