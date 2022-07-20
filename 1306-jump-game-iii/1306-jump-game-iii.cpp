class Solution {
public:
    int dp[50001];
    unordered_set<int> st;
    int reachable(int i, vector<int>& arr){
        if(arr[i]==0) return 1;
        if(dp[i]!=-1) return dp[i];
        if(st.find(i)!=st.end()) return dp[i]=0;
        st.insert(i);
        if(i+arr[i]< arr.size()){
            if(reachable(i+arr[i], arr)==1) return dp[i]=1;
        }
        if(i-arr[i]>=0){
            if(reachable(i-arr[i], arr)==1) return dp[i]=1;
        }
        
        
        return dp[i]=0;
    }
    
    bool canReach(vector<int>& arr, int start) {
        memset(dp, -1, sizeof dp);
        return reachable(start, arr);
        
    }
};