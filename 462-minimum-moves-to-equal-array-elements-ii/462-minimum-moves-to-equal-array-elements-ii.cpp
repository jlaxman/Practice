class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> prefix(nums.begin(), nums.end());
        for(int i=1;i<n; i++){
            prefix[i]+=prefix[i-1];
        }
        long long misteps=INT_MAX;
        for(long long i=0; i<n; i++){
           long long currsteps=INT_MAX;
            if(i!=0){
                currsteps=abs(prefix[i-1]-  i*nums[i])+ abs(prefix[n-1]-prefix[i] -(n-(i+1))*nums[i]);
                misteps= min(currsteps, misteps);
            }else{
                currsteps=abs(prefix[n-1]-prefix[i] -1LL*(n-(i+1))*nums[i]);
                misteps=min(currsteps, misteps);
            }
        }
        return misteps;
        
        
    }
};