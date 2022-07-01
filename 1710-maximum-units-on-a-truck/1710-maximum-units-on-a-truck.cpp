class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto comp=[](auto& x, auto& y){
            return x[1]==y[1]? x[0]> y[0]: x[1]> y[1];
        };
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int totalUnits=0;
        for(auto box: boxTypes){
            int boxesu=min(truckSize, box[0]);
            totalUnits+= (boxesu* box[1]);
            truckSize-=boxesu;
            if(truckSize==0) return totalUnits;
            
        }
       return totalUnits;
        
    }
};