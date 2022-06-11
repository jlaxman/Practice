class Solution {
// public:
//     int minOptozero(int i, int j, int x, vector<int>& nums,  vector<vector<int>>& dp){
//         if(x<0) return INT_MAX;
//         if(x==0) return 0;
//         if(i>j){
//             return INT_MAX;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         int op1=minOptozero(i+1, j, x-nums[i], nums, dp);
//         int op2=minOptozero(i, j-1, x-nums[j], nums, dp);
//         if(op1!=INT_MAX){
//             op1++;
//         }
//         if(op2!=INT_MAX){
//             op2++;
//         }
//         return dp[i][j]=min(op1, op2);
        
//     }

public:
    int minOperations(vector<int>& nums, int x) {
        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        // int op=minOptozero(0, nums.size()-1, x, nums, dp);
        // if(op==INT_MAX) return -1;
        // else return op;
        
        int n=nums.size();
        int sum= accumulate(nums.begin(), nums.end(), 0);
        sum-=x;
        if(sum<0) return -1;
        if(sum==0) return n;
        int j=0;
        int l=-1;
        int curr=0;
        for(int i=0; i<n; i++){
            curr+=nums[i];
            while(j<=i && curr>sum){
                curr-=nums[j];
                j++;
            }
            if(curr==sum){
                l=max(l, i-j+1);
            }
        }
        return l==-1?-1:n-l;
        
        
    }
};