class Solution {
public:
    int dp[100001];
    int maxCost(int i, vector<int>& nums, int k){
        if(i==nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        for(int j=i+1; j<= min(i+k, (int)nums.size()-1); j++){
            ans=max(ans, nums[j]+maxCost(j, nums, k));
            
        }
        return dp[i]=ans;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp);
        int n=nums.size();
        dp[n-1]=nums[n-1];
        priority_queue<pair<int, int>> pq;
        pq.push({nums[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            while(!pq.empty() && (pq.top().second>min(i+k, n-1))){
                pq.pop();
            }
            dp[i]= nums[i]+pq.top().first;
            pq.push({dp[i], i});
        }
        return dp[0];
        
        
        
    }
};