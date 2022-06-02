class Solution {
private:
    int cnt;
    int M;
public:
    void recurse(int i, int n, int k, vector<int>& nums){
        if(i==n){
            if(k==M) cnt++;
            return ;
        }
        // pick
        int _k=k;
        _k|=nums[i];
        recurse(i+1, n, _k, nums);
        //not pick
        recurse(i+1, n, k, nums);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(auto num: nums){
           maxi|=num;
        }
        M=maxi;
        cnt=0;
        recurse(0, nums.size(), 0, nums);
        return cnt;
        
        
        
    }
};