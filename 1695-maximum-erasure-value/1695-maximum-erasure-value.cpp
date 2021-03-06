class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       vector<int> freq(10004, -1);
        vector<int> prefix(nums.size(), nums[0]);
        for(int i=1; i<nums.size(); i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int j=0;
        int sum=0;
        int mx=0;
        for(int i=0; i<nums.size(); i++ ){
            if(freq[nums[i]]==-1){
                freq[nums[i]]=i;
                
            }else{
                j=max(j, freq[nums[i]]+1);
                freq[nums[i]]=i;
            }
            if(j!=0){
                    sum= prefix[i]-prefix[j-1];
                }else{
                    sum=prefix[i];
                }
                mx=max(sum, mx);
            
            
        }
        return mx;

        
        
    }
};