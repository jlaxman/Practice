class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        
        int deltay1=points[1][1]-points[0][1];
        int deltax1=points[1][0]-points[0][0];
        int deltay2=points[2][1]-points[0][1];
        int deltax2=points[2][0]-points[0][0];
        
        return !(deltay1*deltax2 == deltay2* deltax1);
        
        
    }
};