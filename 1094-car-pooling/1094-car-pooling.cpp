class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // auto comp=[](auto& x, auto& y){
        //     return x[1]==y[1]? x[2]<y[2]: x[1]<y[1];
        // }
        // sort(trips.begin(), trips.end(), comp);
        unordered_map<int, int> mpp;
        for(auto t: trips){
            mpp[t[1]]+= t[0];
            mpp[t[2]]-= t[0];
        }
        int prevend=-1;
        int curr=capacity;
        for(int i=0; i<=1000; i++){
            if(curr- mpp[i]<0){
                return 0;
            }else{
                curr-=mpp[i];
            }
        }
        return 1;
    }
};