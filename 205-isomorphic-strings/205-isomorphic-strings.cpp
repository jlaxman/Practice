class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> alpha(256, -1),beta(256, -1);
        for(int i=0; i<s.size(); i++){
            if(alpha[s[i]]==-1 && beta[t[i]]==-1){
                alpha[s[i]]=t[i];
                beta[t[i]]=s[i];
            }else if(alpha[s[i]]!= t[i]  || beta[t[i]]!=s[i]) return 0;
        }
        return 1;
        
        
    }
};