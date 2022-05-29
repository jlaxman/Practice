class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> alpha(26, 0);
        vector<int> beta(26, 0);
        for(auto ch: s){
            alpha[ch-'a']++;
        }
        for(auto ch: t){
            beta[ch-'a']++;
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(alpha[i]!= beta[i]){
                ans+= (abs(alpha[i]-beta[i]));
            }
        }
        return ans;
    }
};