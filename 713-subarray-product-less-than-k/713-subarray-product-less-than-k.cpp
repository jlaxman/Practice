class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int p=1;
        int j=0;
        int ans=0;
        int i;
        for(i=0; i<n; i++){
            p*=nums[i];
            while(p>=k && j<n){
               ans+=(i-j); 
                p/=nums[j++];
            }
        }
        ans+= ((i-j)*(i-j+1)/2);
        return ans<0? 0: ans;
        
    }
};