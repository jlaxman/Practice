class Solution {
// public: 
//    long long hash(string const& s) {
//     const int p = 31;
//     const int m = 1e9 + 9;
//     long long hash_value = 0;
//     long long p_pow = 1;
//     for (char c : s) {
//         hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
//         p_pow = (p_pow * p) % m;
//     }
//     return hash_value;
// }
public:
    string longestWord(vector<string>& words) {
        
        unordered_set<string> mpp;
        for(auto s: words){
            mpp.insert(s);
        }
        vector<string> ans;
        int mx=0;
        for(int i=0; i<words.size(); i++){
            string w= words[i];
            string temp;
            int flag=0;
            for(auto ch: w){
                temp+=ch;
                if(mpp.find(temp)==mpp.end()){
                    flag=1;
                    break;
                }
            }
            if(flag==1) continue;
            if(w.size()>mx){
                mx=w.size();
                ans.clear();
                ans.push_back(w);
            }
            if(w.size()==mx){
                ans.push_back(w);
            }
            
        }
        sort(ans.begin(), ans.end());
        if(ans.size()==0) return {};
        return ans[0];
        
    }
};