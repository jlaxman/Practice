class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       vector<int> freq(10004, 0);
        int j=0;
        int sum=0;
        int mx=0;
        for(int i=0; i<nums.size(); i++ ){
            if(freq[nums[i]]==0){
                sum+= nums[i];
                freq[nums[i]]++;
                mx=max(sum, mx);
                continue;
            }
            while(freq[nums[i]]!=0){
                sum-=nums[j];
                freq[nums[j]]--;
                j++;
            }
            freq[nums[i]]++;
            sum+=nums[i];
            
        }
        return mx;

        
        
    }
};