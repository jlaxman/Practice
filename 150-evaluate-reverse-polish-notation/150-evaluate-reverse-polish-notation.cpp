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
            
           if( tokens[i].size()>1 || (tokens[i][0]-'0'>=0 && tokens[i][0]-'0'<=9)){
               st.push(stoi(tokens[i]));
           }else{
               int a1=st.top();
               st.pop();
               int a2= st.top();
               st.pop();
               int res;
               
              switch(tokens[i][0])
              {
                  case '+': res=a1+a2; break;
                  case '-': res=a2-a1; break;
                  case '*': res=a2*a1; break;
                  case '/': res=a2/a1; break;
                      
              }
               st.push(res);
           }
            
        }
        return st.top();
        
    }
};