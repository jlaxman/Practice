// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function


long long int count(long long int n)
{
   if(n==0) return 1LL;
   long long int c3= n/3;
   long long int c5= n/5;
   long long int c10= n/10;
   long long int cnt=0LL;
  for(long long i=0; i<=c3; i++){
      for(long long j=0; j<=c5; j++){
          for(long long k=0; k<=c10; k++){
              if(i*3+ j*5+ k*10==n) cnt++;
          }
      }
  }
  return cnt;
	
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends