class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        sum=accumulate(nums.begin(), nums.end(), 0);
        int ps=0;
        for(int i=0; i<nums.size(); i++){
            sum-=nums[i];
            if(ps==sum){
                return i;
            }
            ps+=nums[i];
        }
        return -1;
        
    }
};