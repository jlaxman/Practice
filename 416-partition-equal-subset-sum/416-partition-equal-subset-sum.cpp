class Solution {
  int dp[201][20005];  
public:
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        int sum=0;
        sum= accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return 0;
        sum/=2;
        return canpartition(nums.size()-1, nums, sum);
    }
     bool canpartition(int i, vector<int>& nums, int sum){
         if(i==0){
             if(sum==0){
                 return 1;
             }else{
                 return 0;
             }
         }
         if(sum<0) return 0;
         if(dp[i][sum]!=-1) return dp[i][sum];
          
         return dp[i][sum]= (canpartition(i-1, nums, sum-nums[i]) || canpartition(i-1, nums, sum));
         
        
     }
};