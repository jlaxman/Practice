class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        for(int i=0; i< (1<<(nums.size())); i++){
            vector<int> curr;
            for(int j=0; j<nums.size(); j++){
                if((1<<j) & (i)){
                    curr.push_back(nums[j]);
                }
            }
            subsets.push_back(curr);
        }
        return subsets;
        
    }
};