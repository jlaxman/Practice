class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int> > st;
        st.push(make_pair(s[0], 1));
        for(int i=1; i<s.size(); i++){
            if(!st.empty() && s[i]==st.top().first){
                st.push({s[i], st.top().second+1});
            }else{
                st.push({s[i], 1});
            }
            
            if(st.top().second==k){
                int sz= st.size();
                while(st.size()>sz-k){
                    st.pop();
                }
            }
        }
        string temp;
        while(!st.empty()){
            temp+=st.top().first;
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
        
    }
};