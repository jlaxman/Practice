class Solution {
private: int dp[501][501];
public:
    int L(int i, int j, string word1, string word2){
        if(j==word2.size()) return word1.size()-i;
        if(i==word1.size()) return word2.size()-j;
        int op1, op2, op3;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(word1[i]!=word2[j]) op1= 1+L(i+1, j+1, word1, word2);
        else op1= L(i+1, j+1, word1, word2);
        op2= 1+L(i, j+1, word1, word2);
        op3=1+L(i+1, j, word1, word2);
        return dp[i][j]=min(op1, min(op2, op3));
        
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        
        int x= word1.size();
        int y= word2.size();
        for(int i=x; i>=0; i-- ){
           
            for(int j=y; j>=0; j--){
                 if(i==x){
                   dp[x][j]= y-j;
                     continue;
                 }
                 if(j==y){
                     dp[i][y]=x-i;
                     continue;
                 }
                if(word1[i]!=word2[j]) dp[i][j]=min(1+dp[i+1][j+1], min(1+ dp[i][j+1], 1+dp[i+1][j]));
                else dp[i][j]=min(dp[i+1][j+1], min(1+ dp[i][j+1], 1+dp[i+1][j]));
            }
        }
        return dp[0][0];
        
        
    }
};