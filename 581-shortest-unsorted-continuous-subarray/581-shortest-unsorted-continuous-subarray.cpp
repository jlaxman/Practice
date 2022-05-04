class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i=0;
        for(i=0; i<nums.size()-1; i++){
            if(nums[i]> nums[i+1]){
                break;
            }
        }
        if(i==nums.size()-1) return 0;
        int low=i;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i]> nums[i+1]){
                break;
            }
        }
        int high=i+1;
        int mini= *min_element(nums.begin()+low, nums.begin()+high+1);
        int maxi= *max_element(nums.begin()+low, nums.begin()+high+1);
        for(int j=high+1;  j<nums.size(); j++){
           if(nums[j]< maxi){
               high++;
           } 
        }
        for(int j=low-1;  j>=0; j--){
            if(nums[j]> mini){
               low--;
           } 
        }
        
        return high-low+1;
        
    }
};