class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(auto n: arr){
            if(n%2==0 && mpp.find(n/2)!=end(mpp)){
                return 1;
            }
            if(mpp.find(2*n)!=end(mpp)){
                return 1;
            }
            mpp[n]++;
            
            
        }
        return 0;
        
    }
};