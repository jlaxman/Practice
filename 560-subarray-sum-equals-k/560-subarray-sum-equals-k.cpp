class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0]=1;
        int cSum=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            cSum+=nums[i];
            if(mpp.find(cSum-k)!=mpp.end()){
                ans+=mpp[cSum-k];
            }
            mpp[cSum]++;
        }
        return ans;
    }
};