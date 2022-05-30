// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 int fun(int i, int w, int val[], int wt[],  vector<vector<int>>& dp, int n){
     if(i==n) return 0;
     if(w<0) return INT_MIN;
     if(dp[i][w]!=-1) return dp[i][w];
     int op1= fun(i+1, w, val, wt, dp, n);
     int op2= fun(i, w-wt[i], val, wt, dp, n);
     if(op2!=INT_MIN){
         op2+= val[i];
     }
     return dp[i][w]=max(op1, op2);
 }
    
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        return fun(0, w, val, wt, dp, n);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends