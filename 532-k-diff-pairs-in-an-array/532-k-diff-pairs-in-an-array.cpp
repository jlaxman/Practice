class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
     set< pair<int, int> > st;
     unordered_map<int, int> mpp;
    
     for(auto a: nums){
         mpp[a]++;
     }
        int cnt=0;
        for(auto m: mpp){
            if(m.second>1) cnt++;
        }
        for(auto a: nums){
            
            
            
            if(mpp[a-k]!=0){
                st.insert({a, a-k});
            }
           if(mpp[a+k]!=0){
                st.insert({a+k, a});
            }
        }
        if(k==0) return cnt;
        return st.size();
        
    }
};