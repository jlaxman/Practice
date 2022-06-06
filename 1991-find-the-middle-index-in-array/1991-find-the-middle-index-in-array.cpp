class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int ls=0;
        int sum= accumulate(nums.begin(), nums.end(), 0);
        for(int i=0; i<nums.size(); i++){
            if(ls==sum-ls-nums[i]) return i;
            ls+=nums[i];
        }
        return -1;
    
    }
};