class Solution {
public:
    bool predicate(int mid, vector<int>& nums, int m){
        int split=0;
        int mx=0;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum>mid){
                sum=nums[i];
                split++;
            }
            mx=max(sum, mx); 
        }
       
        return (split<=m);
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        if(m>n){
            return INT_MAX;
        }
        int l=*max_element(nums.begin(), nums.end());
        int r= sum;
        int ans=INT_MAX;
        while(l<=r){
            int mid= (l)+((r-l)/2);
            
            if(predicate(mid, nums, m-1)){
                r=mid-1;
                ans=min(ans,mid);
            }else{
                l=mid+1;
            }  
        }
        return ans;
        
        
        
        
    }
};