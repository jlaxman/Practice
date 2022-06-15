class Solution {
public:
    unordered_map<string, int> mpp;
    unordered_set<string> st;
    int lSchain(string& en){
        if(en.size()==1) return 1;
        if(mpp.find(en)!=mpp.end()) return mpp[en];
        int ans=1;
        int mx=1;
        for(int i=0; i<en.size(); i++){
            string s= en.substr(0, i)+ en.substr(i+1);
            if(s.size() && st.find(s)!=st.end()){
                ans=1+lSchain(s);
                mx=max(ans, mx);
            }
        }
        return mpp[en]=mx;
    }
    int longestStrChain(vector<string>& words) {
       for(auto w: words){
           st.insert(w);
       }
        int mx=0;
        for(int i=0; i<words.size(); i++){
             mx=max(mx, lSchain(words[i]));
        }
        return mx;
       
        
    }
};