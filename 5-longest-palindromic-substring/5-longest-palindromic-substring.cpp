class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int ans=0;
         string temp;
        for(int i=0; i<n; i++){
            dp[i][i]=1;
            ans=1;
            temp=s[i];
        }
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=2;
                ans=2;
                temp=s.substr(i, 2);
            }
             
        }
       
        for(int l=3; l<=n; l++){
            for(int i=0; i< n-l+1; i++ ){
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1]==j-i-1){
                    dp[i][j]= j-i+1;
                    if(ans<dp[i][j]){
                        temp=s.substr(i, j-i+1);
                        ans=dp[i][j];
                    }
                }
            }
        }
        return temp;
        
    }
};