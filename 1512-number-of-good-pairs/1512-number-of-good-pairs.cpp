class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int i=0;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(mpp.find(nums[i])!=mpp.end()){
                cnt+= mpp[nums[i]];
                mpp[nums[i]]++;
            }else{
                mpp[nums[i]]++;
            }
        }
        return cnt;
    }
};