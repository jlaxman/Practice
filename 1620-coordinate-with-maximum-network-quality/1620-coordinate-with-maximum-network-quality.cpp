class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxi=0;
        vector<int> ans(2, 0);
        for(int x=0; x<=50; x++){
            for(int y=0; y<=50; y++){
                int curr=0;
                for(auto t: towers){
                    double d= sqrt(pow(x-t[0], 2)+pow(y-t[1], 2));
                    if(d<= radius){
                        curr+=(t[2]/(1+d));
                    }
                }
                if(curr>maxi){
                    maxi=curr;
                    ans[0]=x;
                    ans[1]=y;
                }
            }
        }
        return ans;
        
    }
};