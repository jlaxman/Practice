class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        for(auto w: words){
            for(int i=1; i<w.size(); i++){
                auto f=st.find(w.substr(i));
                if(f!=st.end()){
                    st.erase(f);
                }
            }
        }
        int ans=0;
        for(auto it=st.begin(); it!=st.end(); it++){
            ans+=(*it).size()+1;
        }
        return ans;
        
  
    }
};