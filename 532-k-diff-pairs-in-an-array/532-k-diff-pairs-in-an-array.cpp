class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
     
        unordered_map<int, int> mpp;
        for(auto a : nums){
            mpp[a]++;
        }
        int cnt=0;
        for(auto m: mpp){
            if(k!=0 && mpp.find(m.first+k)!= end(mpp)){
                cnt++;
            } 
            if(k==0 && m.second>1){
                cnt++;
            }
        }
        return cnt;
        
        
        
    }    

};