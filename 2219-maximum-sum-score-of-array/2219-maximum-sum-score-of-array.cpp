class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        long long mxsofar=LONG_MIN;
        long long ls=0LL;
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        for(int i=0; i<nums.size(); i++){
            ls+=nums[i];
            long long curr= max(ls, sum-ls+nums[i]);
            mxsofar=max(curr, mxsofar);
            
        }
        return mxsofar;
    }
};