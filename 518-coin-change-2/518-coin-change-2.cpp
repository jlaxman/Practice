class Solution {
public:
    int change(int amt, vector<int>& coins) {
        vector<int> dp(amt+1, 0);
        sort(coins.begin(), coins.end());
        dp[0]=1;
        for(auto c: coins){
            for(int i=c;i<= amt; i++){
                dp[i]+=dp[i-c];
            }
        }
        return dp[amt];
        
    }
};