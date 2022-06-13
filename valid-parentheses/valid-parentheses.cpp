class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='}' || s[i]==']' || s[i]==')'){
                if(st.empty()) return 0;
                else{
                     if(s[i]=='}'){
                         if(st.top()!='{') return 0;
                         else{
                             st.pop();
                         }
                     }
                     else if(s[i]==']'){
                        if(st.top()!='[') return 0;
                         else{
                             st.pop();
                         } 
                     }
                     else{
                        if(st.top()!='(') return 0;
                         else{
                             st.pop();
                         } 
                     }
                    
                    
                }
                
                
                
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
        
    }
};