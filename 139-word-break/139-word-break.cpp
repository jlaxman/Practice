class Solution {
    private:
    unordered_set<string> st;
public:
    int fun(string s, int i, int j, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(st.find(s.substr(i, j-i+1))!=st.end()) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i; k<j; k++){
            bool split1= fun(s, i, k, dp);
            bool split2= fun(s, k+1, j, dp);
            if(split1 && split2) return dp[i][j]=1;
        }
        return dp[i][j]=0;
    }
public:
    bool wordBreak(string s, vector<string>& w) {
        for(auto ch: w){
            st.insert(ch);
        }
        // string temp;
        // st.insert(temp);
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        return fun(s, 0, s.size()-1, dp);
    }
};