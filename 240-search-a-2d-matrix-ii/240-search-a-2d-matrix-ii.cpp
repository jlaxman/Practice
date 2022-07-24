class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for(auto &v: matrix){
        //     for(auto &c: v){
        //         if(c==target) return 1;
        //     }
        // }
        // return 0;
        for(int i=0; i<matrix.size(); i++){
            auto lb=lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(lb!=matrix[i].end() && *lb==target) return 1;
        }
        return 0;
        
        
    }
};