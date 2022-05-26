class Solution {
public:
    int supereggDrop(int k, int n, vector<vector<int>>& dp){
        if(k==1) return n;
       if(n==0 || n==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];
        int mini=1000000;
       // for(int i=1; i<=n; i++){
       //     int ans= 1+max(supereggDrop(k-1, i-1, dp), supereggDrop(k, n-i, dp));
       //     mini=min(ans, mini);
       // }
        int l=1;
        int r= n;
        
        while(l<=r){
            int mid= l+ ((r-l)/2);
            int t1=supereggDrop(k-1, mid-1, dp);
            int t2= supereggDrop(k, n-mid, dp);
            if(t1<t2){
                l=mid+1;
            }else {
                r=mid-1;
            }
            int ans= 1+max(t1, t2);
            mini=min(mini, ans);
            
        }
       
        
        
        return dp[k][n]=mini;
    }
public:
    int superEggDrop(int k, int n) {
       vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return supereggDrop(k, n, dp);
      
        
        
    }
};