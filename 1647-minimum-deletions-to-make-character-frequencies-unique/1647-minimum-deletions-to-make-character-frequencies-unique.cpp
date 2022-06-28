class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto ch: s){
            freq[ch-'a']++;
        }
        unordered_set<int> st;
        int ans=0;
        for(int i=0; i<26; i++){
            if(freq[i]){
                
                while(freq[i]>0 && st.find(freq[i])!=st.end()){
                    freq[i]--;
                    ans++;
                }
                if(freq[i]){
                    st.insert(freq[i]);
                }
            }
        }
        return ans;
        
       
       
        
    }
};