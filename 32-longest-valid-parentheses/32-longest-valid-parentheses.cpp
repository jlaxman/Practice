class Solution {
public:
    int longestValidParentheses(string s) {
       int n= s.size();
       vector<int> dp(n, 0);
        int mx=0;
        for(int i=1; i<n; i++){
            if(s[i]==')'){
                int j= i-dp[i-1]-1;
                if(j>=0 && s[j]=='('){
                    dp[i]= i-j+1;
                    if(j-1>=0) dp[i]+= dp[j-1];
                }
                mx=max(mx, dp[i]);
                    
            }
        }
        return mx;
        
        
    }
};