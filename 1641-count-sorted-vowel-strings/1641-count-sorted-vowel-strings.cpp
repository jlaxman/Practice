class Solution {
    
public:
    int countVowels(int n, int i, vector<vector<int>>& dp){
        if(n==1){
            return 1;
        }
        
        if(dp[n][i]!=-1) return dp[n][i];
        int ans=0;
        for(int k=0; k<=i; k++){
            ans+=countVowels(n-1, k, dp);
        }
        return dp[n][i]=ans;
        
    }
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5, -1));
       
        int s=0;
        for(int i: {0, 1, 2, 3, 4}){
             s+=countVowels(n, i, dp);
        }
        return s;
    }
};