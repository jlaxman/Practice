class Solution {
public:
    int cnt;
    void recurse(int i, vector<int>& nums, int t){
        if(i==nums.size()){
            if(t==0){
                cnt++;
            }
            return;
        }
        recurse(i+1, nums, t+nums[i]);
        recurse(i+1, nums, t-nums[i]);
        return;
        
        
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       cnt=0;
       int n=nums.size();
       recurse(0, nums, target);
       return cnt;
        
    }
};