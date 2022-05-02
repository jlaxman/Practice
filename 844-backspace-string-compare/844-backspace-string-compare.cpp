class Solution {
public:
    bool backspaceCompare(string s, string t) {
          int i=s.size()-1;
          int j=t.size()-1;
        int cnts=0;
        int cntt=0;
        while(i>=0 || j>=0){
            while(i>=0 ){
                  if(s[i]=='#'){cnts++; i--;}
                  else if(cnts> 0) {cnts--; i--;}
                  else break;
                
            }
            while(j>=0 ){
                  if(t[j]=='#'){cntt++; j--;}
                  else if(cntt> 0) {cntt--; j--;}
                  else break;
                
            }
            
           
            if(i>=0 && j>=0 && s[i]!=t[j]) return false;
            if(i>=0 != j>=0) return false;
            
          
                i--;
                j--;
            
            
            
        }
        
        return true;
      
        
    }
};