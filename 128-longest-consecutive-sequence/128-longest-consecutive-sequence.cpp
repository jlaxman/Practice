class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto n: nums){
            mpp[n]++;
        }
        int mxl=0;
        for(auto n: nums){
            if(mpp.find(n-1)==mpp.end()){
                int l=0;
                while(mpp.find(n)!=mpp.end()){
                    l++;
                    n++;
                }
                mxl=max(l, mxl);
            }
        }
        return mxl;
        
    }
};