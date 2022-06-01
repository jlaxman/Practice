class Solution {
int dp[100002][2][3];
public:
    int fun(int i, int state, int k, vector<int>& prices){
        if(k==0) return 0;
        if(i==prices.size()) return 0;
        if(dp[i][state][k]!=-1) return dp[i][state][k];
        if(state==1){
           return dp[i][state][k]=max(fun(i+1, 0, k, prices)-prices[i], fun(i+1, 1, k, prices));
        }else{
            return dp[i][state][k]=max(fun(i+1, 1, k-1, prices)+prices[i], fun(i+1, 0, k, prices));
        }
    }
    int maxProfit(vector<int>& prices) {
       // memset(dp, -1, sizeof dp);
       // return fun(0, 1, 2, prices);
        int t1cost=INT_MAX;
        int t2cost=INT_MAX;
        int p1=0;
        int p2=0;
        for(auto p: prices){
            t1cost= min(p, t1cost);
            p1=max(p1, p-t1cost);
            t2cost=min(t2cost, p-p1);
            p2= max(p2, p-t2cost);
        }
        return p2;
        
    }
};