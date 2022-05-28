class Solution {
public:
    int fun(int i, vector<int>& tr, vector<int>& costs, vector<int> & dp){
        if(i>365){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        if(tr[i]==0){
            return dp[i]=fun(i+1, tr, costs, dp);
        }else{
            return dp[i]=min(costs[0]+ fun(i+1, tr, costs, dp), min(costs[1]+ fun(i+7, tr, costs, dp), costs[2]+fun(i+30, tr, costs, dp)));
        }
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        vector<int> tr(366, 0);
        for(auto d: days){
            tr[d]=1;
        }
        
       return fun(1, tr, costs, dp);
        
    }
};