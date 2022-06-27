class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
       for(auto ch: n){
           maxi=max(ch-'0', maxi);
       }
        return maxi;
    }
};