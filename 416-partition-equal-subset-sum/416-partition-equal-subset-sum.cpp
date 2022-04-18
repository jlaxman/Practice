class Solution {
    int dp[2][201][20005];
public:
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return canpartition(0, nums, 0);
    }
     bool canpartition(int i, vector<int>& nums, int sum){
         if(i==nums.size()){
             if(sum==0) return 1;
             else return 0;
         }
         int sign=1;
         int t=sum;
         if(sum<0){
             sign=0;
             t=-sum;
         }
         if(dp[sign][i][t]!=-1) return dp[sign][i][t]==1;
         return dp[sign][i][t]=(canpartition(i+1, nums, sum+nums[i]) || canpartition(i+1, nums, sum-nums[i]));
        
     }
};