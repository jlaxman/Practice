class Solution {
public:
    vector<int> count(string& s){
        vector<int> alpha(26, 0);
        for(auto ch: s){
            alpha[ch-'a']++;
        }
        
        return alpha;
    }
    bool check(vector<int>& v1, vector<int>& v2){
        for(int i=0; i<26; i++){
            if(v1[i]>0 && v2[i]>0) return 0;
        }
        return 1;
    }
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> dp(words.size());
         for(int i=0; i<words.size(); i++){
             dp[i]=count(words[i]);
         }
            
        
        int ans=0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(check(dp[i], dp[j])){
                    int l= (words[i].size())*(words[j].size());
                    ans= max(l, ans);
                }
            }
        }
        return ans;
        
        
    }
};