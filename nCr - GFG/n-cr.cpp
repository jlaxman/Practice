// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int mod=1e9+7;
    int dp[1001][801];
public:
    int fun(int i, int n, int r){
        if(r>n) return 0;
        if(r<0) return 0;
        if(i==n){
            if(r==0) return 1;
            else return 0;
        }
        if(dp[i][r]!=-1) return dp[i][r];
        int op1=fun(i+1, n, r-1)%mod;
        int op2=fun(i+1, n, r)%mod;
        return dp[i][r]=(op1+op2)%mod;
        
    }
     
    int nCr(int n, int r){
        // code here
        memset(dp, -1, sizeof dp);
        if(r>n) return 0;
        return fun(0, n, r);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends