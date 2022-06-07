class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
       map<long long, long long> mpp;
        if(k==0) return 0;
        for(int i=0; i<nums.size(); i++){
           
            auto it1=mpp.lower_bound((1LL*nums[i]-1LL*t));
            if(it1!=mpp.end()){
                if(abs(it1->first-nums[i])<=t) return 1;
            }
            if(i>=k){
                mpp[nums[i-k]]--;
                if(mpp[nums[i-k]]==0){
                    auto f=mpp.find(nums[i-k]);
                     mpp.erase(f);
                }
            }
            mpp[nums[i]]++;
        }
        return 0;
     }
    
};