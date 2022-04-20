class Solution {
  // bool dp[201][20005];  
public:
    bool canPartition(vector<int>& nums) {
        // memset(dp, nullopt, sizeof dp);
        int sum=0;
        sum= accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return 0;
        sum/=2;
        vector<vector<optional<bool>>> dp(nums.size()+1, vector<optional<bool>>(sum+1, nullopt));
        return canpartition(nums.size()-1, nums, sum, dp);
    }
     bool canpartition(int i, vector<int>& nums, int sum, vector<vector<optional<bool>>> &dp){
         if(i==0){
             if(sum==0){
                 return 1;
             }else{
                 return 0;
             }
         }
         if(sum<0) return 0;
         if(dp[i][sum]!= nullopt) return dp[i][sum]==true;
         bool result=(canpartition(i-1, nums, sum-nums[i], dp) || canpartition(i-1, nums, sum, dp));
          
         dp[i][sum]= result;
         return result;
         
        
     }
};