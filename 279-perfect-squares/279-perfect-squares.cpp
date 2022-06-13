class Solution {
public:
    int minSteps(int i, int n, vector<int>& ps, int k,  vector<vector<int>>& dp){
        if(i==n){
            if(k!=0) return INT_MAX;
            else return 1;
        }
        if(k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int op1=INT_MAX;
        int op2=INT_MAX;
        if(k>= ps[i]) op1= minSteps(i, n, ps, k-ps[i], dp );
        if(op1!=INT_MAX) op1++;
        op2=minSteps(i+1, n, ps, k, dp );
        return dp[i][k]=min(op1, op2);
    }
public:
    int numSquares(int n) {
        vector<int> ps;
        for(int i=1; i<=sqrt(n); i++){
            ps.push_back(i*i);
        }
        vector<vector<int>> dp(ps.size()+1, vector<int>(n+1, -1));
        
        return minSteps(0, ps.size(), ps, n, dp);
        
    }
};