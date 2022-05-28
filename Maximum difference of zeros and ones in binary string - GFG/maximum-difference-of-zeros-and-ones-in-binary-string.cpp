// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    int ans=0;
	    int mxans=0;
	    for(int i=0; i<n; i++){
	        if(s[i]=='0'){
	            ans++;
	             
	        }else{
	          ans--;
	          if(ans<0) ans=0;
	        }
	        mxans=max(ans, mxans);
	    }
	    return mxans==0? -1: mxans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends