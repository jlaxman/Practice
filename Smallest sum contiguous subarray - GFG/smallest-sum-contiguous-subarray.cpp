// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
       int n=a.size();
       long long curr_max=a[n-1];
       long long mxsum =a[n-1];
        for(int i=n-2; i>=0; i--){
            curr_max=min(1LL*a[i], curr_max+a[i]);
            mxsum=min(mxsum, curr_max);
        }
        return (int)mxsum;
  }
};


// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends