class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto &v: matrix){
            for(auto &c: v){
                if(c==target) return 1;
            }
        }
        return 0;
        
    }
};