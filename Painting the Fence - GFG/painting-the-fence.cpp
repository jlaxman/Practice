// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    long long m=1e9+7;
    public:
    long long countWays(int n, int k){
        // code here
        if(n==1) return k;
        long long curr=((k*k)%m);
        long long prev=k%m;
        long long temp;
        for(int i=3; i<=n; i++){
            temp=curr;
            curr=((curr*(k-1))%m+ ((prev*(k-1))%m))%m;
            prev=temp;
        }
        return curr;
    }
    
    
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends