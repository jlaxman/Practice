class Solution {
   
public:
    int fun(int i, int j, vector<int>& nums, vector<vector<vector<int>>>& dp, int p){
        if(i>j) return 0;
        if(dp[i][j][p]!=-1) return dp[i][j][p];
        if(p==0){
            return max(nums[i]+fun(i+1, j, nums, dp, 1), nums[j]+fun(i, j-1, nums, dp, 1));
        }else{
            return min(fun(i+1, j, nums, dp, 0), fun(i, j-1, nums, dp, 0));
        }
    }
    
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return fun(0, n-1, nums, dp, 0)>=(sum+1)/2;
    }
};