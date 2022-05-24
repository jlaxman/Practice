class Solution {
public:
    int longestValidParentheses(string s) {
       int n=s.size();
       vector<int> vec(n , -1);
       stack<int>  st;
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                if(!st.empty()){
                    int k= st.top();
                    st.pop();
                    vec[i]=i-k+1;
                }
            }else{
                st.push(i);
            }
        }
        int l=0;
        int mxl=0;
        for(int i=0; i<n; i++){
            if(vec[i]!=-1){
                int ans= i-vec[i];
                int bl=0;
                if(ans>=0){
                    if(vec[ans]!=-1) bl= vec[ans];
                }
                l= vec[i]+bl;
                vec[i]=l;
                mxl=max(l, mxl);
            }
        }
        return mxl;
        
        
    }
};