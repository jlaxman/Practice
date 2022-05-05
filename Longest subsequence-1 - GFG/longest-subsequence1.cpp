// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<int> dp(N+1, -1);
        int mx=0;
        for(int i=0; i<N; i++){
           mx= max(1+LiS(i, N, A, dp), mx);
        }
        return mx;
        
    }
    int LiS(int i, int n, int A[], vector<int> & dp){
        int ans=0;
        int mx=0;
        if(dp[i]!=-1) return dp[i];
        for(int k=i+1; k<n; k++){
            if(abs(A[k]-A[i])==1){
                ans=(1+LiS(k, n, A, dp));
                mx=max(ans, mx);
            }
        }
        return dp[i]=mx;
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends