class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof dp);
        string ans;
        int maxl=1;
        ans=s[0];
        int start=0;
        
        for(int i=0; i<n; i++) dp[i][i]=1;
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                start=i;
                maxl=2;
            }
        }
        
        for(int l=3; l<=n; l++){
            for(int i=0; i<=n-l; i++){
                if(s[i]==s[i+l-1] && dp[i+1][i+l-2]){
                    dp[i][i+l-1]=1;
                }
                if(dp[i][i+l-1] && l>maxl){
                    maxl=l;
                    start=i;
                }
            }
        }
        return s.substr(start, maxl);
        
    }
};