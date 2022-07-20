class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> q(26, vector<int>());
        for(int i=0;i<s.size(); i++){
            q[s[i]-'a'].push_back(i);
        }
        int cnt=0;
        unordered_set<string> st;
        for(auto w: words){
            
            
            int flag=0;
            int prev=-1;
            for(auto ch: w){
                
                if(q[ch-'a'].size()==0){
                    flag=1;
                    break;
                }
                int ind=upper_bound(q[ch-'a'].begin(), q[ch-'a'].end(), prev)-q[ch-'a'].begin();
                if(ind==q[ch-'a'].size()){
                    flag=1;
                    break;
                }else{
                    prev=q[ch-'a'][ind];
                }
            }
            if(flag==0){
                // cout<< w<<endl;
                // st.insert(w);
                cnt++;
            }
            
            
        }
        return cnt;
        
    }
};