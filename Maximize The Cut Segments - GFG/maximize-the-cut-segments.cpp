// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[n+1];
        memset(dp, -1, sizeof dp);
        return (fun(n, x, y, z, dp)<0)? 0: dp[n];
    }
    int fun(int n, int x, int y, int z, int dp[]){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int op1=0;
        int op2=0;
        int op3=0;
        if(n>=x){
            op1=1+ fun(n-x, x, y, z, dp);
        }
         if(n>=y){
            op2=1+ fun(n-y, x, y, z, dp);
        }
         if(n>=z){
            op3=1+ fun(n-z, x, y, z, dp);
        }
        return dp[n]= (max(op1, max(op2, op3))==0)? INT_MIN : max(op1, max(op2, op3));
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends