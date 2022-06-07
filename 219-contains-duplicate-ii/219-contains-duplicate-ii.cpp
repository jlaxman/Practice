class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]]!=0) return true;
            
            if(i>=k){
                mpp[nums[i-k]]--;
            }
            mpp[nums[i]]++;
        }
        return 0;
    }
};