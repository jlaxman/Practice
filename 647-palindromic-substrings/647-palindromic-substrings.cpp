class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[i][i]=1;
            if(i+1<n && s[i]==s[i+1]){
                dp[i][i+1]=1;
            }
        }
        for(int l=3; l<=n; l++){
            for(int i=0; i<n; i++){
                if(i+l-1 <n){
                    int j=i+l-1;
                    if(s[i]==s[j]){
                        if(dp[i+1][j-1]==1){
                            dp[i][j]=1;
                        }
                    }
                }
            }
        }
        int sum=0;
       for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               sum+=dp[i][j];
           }
       }
        return sum;
        
    }
};