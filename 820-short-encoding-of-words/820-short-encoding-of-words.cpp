class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        auto comp=[](auto& x, auto& y){
            return x.size()>y.size();
        };
        sort(words.begin(), words.end(), comp);
        unordered_set<string> st;
        int cnt=0;
        int sz=0;
        for(int i=0; i<words.size(); i++){
            string s=words[i];
            if(st.find(s)==st.end()){
                for(int j=0; j<s.size(); j++){
                    st.insert(s.substr(j));
                }
                sz+=s.size();
                cnt++;
            }
        }
        return (sz+cnt);
        
        
    }
};