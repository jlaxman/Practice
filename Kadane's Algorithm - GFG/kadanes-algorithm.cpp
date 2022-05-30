// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
   
    public:
    // long long dp[1000001];
    long long fun(int i, int arr[], int n, vector<long long>& dp){
        if(i>=n) return 0LL;
        if(dp[i]!=-1) return dp[i];
        long long op1=1LL*arr[i]+fun(i+1, arr, n, dp);
        long long op2= 1LL*arr[i];
        return dp[i]=max(op1, op2);
    }
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        // memset(dp , -1000001, sizeof dp);
        vector<long long> dp(n+1, -1);
        // Your code here
        
        fun(0, arr, n, dp);
        long long mxsum=1LL*arr[0];
        for(int i=0; i<n; i++){
          mxsum= max(mxsum, dp[i]);
        // cout<< dp[i]<<endl;
        }
        // long long curr_max=arr[n-1];
        // long long mxsum =arr[n-1];
        // for(int i=n-2; i>=0; i--){
        //     curr_max=max(1LL*arr[i], curr_max+arr[i]);
        //     mxsum=max(mxsum, curr_max);
        // }
        return mxsum;
    
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends