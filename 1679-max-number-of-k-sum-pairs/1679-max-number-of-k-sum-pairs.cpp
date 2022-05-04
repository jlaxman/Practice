class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int cnt=0;
        for(auto n: nums){
            if(mpp.find(k-n)!=mpp.end() && mpp[k-n]!=0){
                cnt++;
                mpp[k-n]--;
               
            }else{
                mpp[n]++;
            }
        }
        return cnt;
        
    }
};