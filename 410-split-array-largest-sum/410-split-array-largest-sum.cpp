class Solution {
public:
    int mini=INT_MAX;
    bool predicate(int mid, vector<int>& nums, int m){
        int mx=0;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum>mid){
                sum=nums[i];
                m--;
            }
            mx=max(sum, mx); 
        }
        if(m>=0){
            mini=min(mx, mini);
        }
        return m>=0;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        if(m>n){
            return INT_MAX;
        }
        int l=0;
        int r= sum;
        int ans=INT_MAX;
        while(l<=r){
            int mid= (l)+((r-l)/2);
            
            if(predicate(mid, nums, m-1)){
                r=mid-1;
                ans=min(mid, ans);
            }else{
                l=mid+1;
            }  
        }
        return mini;
        
        
        
        
    }
};