class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size(), vector<int>(2, -1));
        auto comp=[](auto& x, auto& y){
            return x[0]==y[0]? x[1]>y[1]: x[0]<y[0];
        };
        sort(people.begin(), people.end(), comp);
        for(int i=0; i<people.size(); i++){
           int cnt=0;
           for(int j=0; j<people.size(); j++){
               if(ans[j][0]!=-1) continue;
               if(cnt==people[i][1]){
                   ans[j][0]=people[i][0];
                   ans[j][1]=people[i][1];
                   break;
               }
               cnt++;
           }
        }
        return ans;
        
    }
};