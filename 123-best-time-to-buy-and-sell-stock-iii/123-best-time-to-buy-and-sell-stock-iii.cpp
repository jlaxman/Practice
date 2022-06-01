class Solution {
// int dp[100002][2][3];
// public:
//     int fun(int i, int state, int k, vector<int>& prices){
//         if(k==0) return 0;
//         if(i==prices.size()) return 0;
//         if(dp[i][state][k]!=-1) return dp[i][state][k];
//         if(state==1){
//            return dp[i][state][k]=max(fun(i+1, 0, k, prices)-prices[i], fun(i+1, 1, k, prices));
//         }else{
//             return dp[i][state][k]=max(fun(i+1, 1, k-1, prices)+prices[i], fun(i+1, 0, k, prices));
//         }
//     }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][2][3];
        memset(dp, -1, sizeof dp);
        for(int i=0; i<2; i++){
              for(int k=0; k<3; k++){
                  dp[n][i][k]=0;
              }
         }
        for(int i=0; i<=n; i++){
            dp[i][0][0]=0;
            dp[i][1][0]=0;
        }
        for(int i=n-1; i>=0; i--){
            for(int s=0; s<2; s++){
              for(int k=1; k<3; k++){
                  if(s==1){
                      dp[i][s][k]=max(dp[i+1][1-s][k]-prices[i], dp[i+1][s][k]);
                  }else{
                       dp[i][s][k]=max(dp[i+1][1-s][k-1]+prices[i], dp[i+1][s][k]);
                  }
              }
            }     
        }
        
        return dp[0][1][2];
       
        
    }
};