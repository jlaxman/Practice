class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mpp;
        for(int i=0; i<nums.size(); i++){
         mpp[nums[i]].push_back(i);
        }
        int cnt=0;
        for(auto m: mpp){
            vector<int> temp= m.second;
            for(int i=0; i<temp.size(); i++){
               int I=temp[i];
                for(int j=i+1; j< temp.size(); j++){
                    int J= temp[j];
                    if((I*J)%k==0) cnt++;
                }
                
            }
        }
        return cnt;
        
    }
};