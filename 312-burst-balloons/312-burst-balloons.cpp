class Solution {
    int dp[301][301];
public:
    int fun(int start, int end, vector<int>& nums){
       
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=INT_MIN;
        for(int k=start; k<=end; k++){
            int left=1;
            int right=1;
            if(start-1>=0 && start-1<nums.size()){
                left=nums[start-1];
            }
            if(end+1>=0 && end+1< nums.size()){
                right=nums[end+1];
            }
            int c= fun(start, k-1, nums)+ fun(k+1, end, nums)+ (left*nums[k]*right);
            ans=max(c, ans);
        }
        return dp[start][end]=ans;
        
    }
    int maxCoins(vector<int>& nums) {
       
        
            memset(dp, -1, sizeof dp);
            int end=nums.size()-1;
            return fun(0, end, nums);
        }
    
};