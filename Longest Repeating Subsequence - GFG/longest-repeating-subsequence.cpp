// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    vector<vector<int>> dp(str.size()+1, vector<int>(str.size()+1, -1));
		    return LCS(0, 0, str, str, dp);
		}
		int LCS(int i, int j, string& s1, string& s2,  vector<vector<int>>& dp){
        if(i==s1.size() || j==s2.size()){
          return 0;  
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j] && i!=j){
            ans=1+LCS(i+1, j+1, s1, s2, dp);
            return dp[i][j]=ans;
        }else{
            int ans1= LCS(i+1, j, s1, s2, dp);
            int ans2= LCS(i, j+1, s1, s2, dp);
            return dp[i][j]=max(ans1, ans2);
            
        }
        
    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends