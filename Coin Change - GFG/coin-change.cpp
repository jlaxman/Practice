// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    long long int dp[1001][1001];
  public:
    long long int count(int S[], int m, int n) {
        memset(dp, -1, sizeof dp);
         return Count(0, S, m, n);
    }
    long long int Count(int i, int S[], int m, int n){
        if(i==m)
        {
            if(n==0) return 1;
            else return 0;
        }
        if(n<0) return 0;
        if(dp[i][n]!=-1) return dp[i][n];
        long long int op1=Count(i, S, m, n-S[i]);
        long long int op2=Count(i+1, S, m, n);
        return dp[i][n]=op1+op2;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends