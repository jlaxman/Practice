class Solution {
public:
//     int fun(int i, int p, vector<int>& nums, vector<vector<int>>& dp, int n){
        
//         if(dp[i][p]!=-1) return dp[i][p];
//         int ans=1;
//         if(p==0){
//            for(int k=i+1; k<n; k++){
//                if(nums[k]>nums[i]){
//                    ans=max(ans, 1+fun(k, 1-p, nums, dp, n));
//                }
//            }
        
//         }else {
//             for(int k=i+1; k<n; k++){
//                if(nums[k]<nums[i]){
//                    ans=max(ans, 1+fun(k, 1-p, nums, dp, n));
//                }
//            }
            
//         }
//         return dp[i][p]=ans;
//     }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        // int ans=0;
        // for(int i=0; i<n; i++){
        //     ans=max(ans, fun(i, 0, nums, dp, n));
        //     ans=max(ans, fun(i, 1, nums, dp, n));
        // }
        // return ans;
        
        // vector<int> dph(n, 0);
        // vector<int> dpl(n, 0);
        int dph=1;
        int dpl=1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                dph= 1+dpl;
               
            }else if(nums[i]<nums[i+1]){
                dpl= 1+dph;
                
            }else{
                // dph[i]=dph[i+1];
                // dpl[i]=dpl[i+1];
            }
        }
        return max(dpl, dph);
        
    }
};