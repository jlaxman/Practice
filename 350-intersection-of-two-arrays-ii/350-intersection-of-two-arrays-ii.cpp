class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        for(auto n: nums1){
            mpp[n]++;
        }
        vector<int> ans;
        for(auto a: nums2){
            if(mpp.find(a)!=mpp.end()){
                ans.push_back(a);
                mpp[a]--;
                auto f=mpp.find(a);
                if(mpp[a]==0){
                    mpp.erase(a);
                }
            }
        }
        return ans;
        
    }
};