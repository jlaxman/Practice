class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        //quick select
        int j=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]%2==0){
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
        return nums;
        
    }
};