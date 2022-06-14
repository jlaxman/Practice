class Solution {
public:
    int cnt;
    int dp[21][3002];
    int recurse(int i, vector<int>& nums, int t){
        if(i==nums.size()){
            if(t==0){
                return 1;
            }
            return 0;
        }
        // if(t < -1000 || t>1000) return 0;
        if(dp[i][1000+t]!=-1) return dp[i][1000+t];
        int op1=recurse(i+1, nums, t+nums[i]);
        int op2=recurse(i+1, nums, t-nums[i]);
        
        return dp[i][1000+t]=op1+op2;
        
        
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       cnt=0;
       int n=nums.size();
       memset(dp, -1, sizeof dp);
       return recurse(0, nums, target);
        
    }
};