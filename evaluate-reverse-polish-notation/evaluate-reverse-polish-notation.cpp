class Solution {
public:
    int check(string t){
        for(auto ch: t){
            if(!isdigit(ch)){
                return INT_MAX;
            }
        }
        return stoi(t);
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            
           if(tokens[i].size()>1 || isdigit(tokens[i][0])){
               st.push(stoi(tokens[i]));
           }else{
               int a1=st.top();
               st.pop();
               int a2= st.top();
               st.pop();
               if(tokens[i]=="+"){
                   st.push(a1+a2);
               }else if(tokens[i]=="*"){
                   st.push(a1*a2);
               }else if(tokens[i]=="-"){
                   st.push(a2-a1);
               }else{
                   st.push(a2/a1);
               }
           }
            
        }
        return st.top();
        
    }
};