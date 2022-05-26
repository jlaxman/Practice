class Solution{
    
public: 
//     int fun(int i,  vector<int>& dp, vector<vector<int>>& pairs, int n){
//         if(dp[i]!=-1) return dp[i];
//         int ans=1;
//        for(int k=i+1; k<n; k++){
//            if(pairs[k][0]> pairs[i][1]){
//                ans= max(1+fun(k, dp, pairs, n), ans); 
//            }
//        }
//         return dp[i]=ans;
        
//     }
    int findLongestChain(vector<vector<int>>& pairs) {
        auto comp=[](auto& x, auto& y){
            return x[1]<y[1];
        };
        sort(pairs.begin(), pairs.end(), comp);
        int ans=1;
        int n=pairs.size();
        int curr=pairs[0][1];
        for(int i=1; i<n; i++){
            if(curr<pairs[i][0]){
                ans++;
                curr=pairs[i][1];
            }
        }
        return ans;
    }
};