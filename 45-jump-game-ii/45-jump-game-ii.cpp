class Solution {
// public:
//   int fun(int i, vector<int>& arr, int n, vector<int>& dp){
//       if(i>=n-1){
//           return 0;
//       }
//       if(arr[i]==0) return 10000002;
//       if(dp[i]!=-1) return dp[i];
//       int ans=INT_MAX;
//       for(int j=i+1; j<= arr[i]+i; j++ ){
//           ans= min(1+fun(j, arr, n, dp), ans);
//       }
//       return dp[i]=ans;
//   }
public:
    int jump(vector<int>& arr) {
        // vector<int> dp(nums.size()+1, -1);
        // int ans=fun(0, nums, nums.size(), dp);
        // if(ans>= 10000002) return -1;
        // return ans; 
        
        int n=arr.size();
        int i=0;
        int maxstep= i+arr[i];
        
        i=1;
        int steps=0;
        int ind=0;
       while(i<n){
           int curr=0;
           while(i<n && i<=maxstep){
               if(curr< i+arr[i]){
                   ind=i;
                   curr=arr[i]+i;
               }
               i++;
           }
          
           steps++;
           if(i>=n) break;
           i=ind+1;
           maxstep=curr;
           
       }
        return steps;
    }
};