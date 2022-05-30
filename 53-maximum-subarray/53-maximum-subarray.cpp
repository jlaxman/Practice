class Solution {
long long dp[100001];
public:
    long long fun(int i, vector<int>& nums){
      if(i==nums.size()) return 0;
      if(dp[i]!=-1) return dp[i];
      return dp[i]=max(1LL*nums[i], 1LL*nums[i]+fun(i+1, nums));
    }
    
public:
    int maxSubArray(vector<int>& nums) {
       memset(dp, -1, sizeof dp);
       fun(0, nums);
       long long mxsum=INT_MIN;
       for(int i=0; i<nums.size(); i++){
           mxsum=max(mxsum, dp[i]);
       }
        return mxsum;
    }
};