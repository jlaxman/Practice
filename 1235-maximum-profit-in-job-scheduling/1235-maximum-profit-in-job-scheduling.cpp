class Solution {
public:
    int fun(int i, vector<vector<int>>& vec, vector<int>& dp, int n){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        vector<int> temp={vec[i][1], 0, 0};
        int ind= lower_bound(vec.begin()+i+1, vec.end(), temp)-vec.begin();
        return dp[i]=max(vec[i][2]+fun(ind, vec, dp, n) , fun(i+1, vec, dp, n));
    }
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n=s.size();
        vector<vector<int>> vec;
        vector<int> dp(n+1, -1);
        for(int i=0; i<n; i++){
            vec.push_back({s[i], e[i], p[i]});
        }
        // auto comp=[](auto& x, auto& y){
        //     return x[1]==y[1] ? x[2]>y[2] : x[1]<y[1];
        // };
        sort(vec.begin(), vec.end() );
        
        return fun(0, vec, dp, n);
        
        
        
    }
};