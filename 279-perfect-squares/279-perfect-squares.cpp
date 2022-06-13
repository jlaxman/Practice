class Solution {
public:
    int minSteps(int n, vector<int>& ps, int k,  vector<int>& dp){
        
        if(k==0) return 0;
        if(dp[k]!=-1) return dp[k];
        int ans=INT_MAX;
        int mini=INT_MAX;
        for(int j=0; j<n; j++){
            if(k>=ps[j]){
                ans= minSteps(n, ps, k-ps[j], dp);
                if(ans!=INT_MAX){
                    ans++;
                    mini=min(ans, mini);
                } 
            }else{
                break;
            }
        }
        return dp[k]=mini;
       
       
    }
public:
    int numSquares(int n) {
        vector<int> ps;
        for(int i=1; i<=sqrt(n); i++){
            ps.push_back(i*i);
        }
     vector<int> dp(n+1, -1);
        
        return minSteps(ps.size(), ps, n, dp);
        
    }
};