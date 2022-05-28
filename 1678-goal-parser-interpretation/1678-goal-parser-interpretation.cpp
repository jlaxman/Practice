class Solution {
public:
    string interpret(string s) {
        string temp;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='G'){
                temp+='G';
            }else{
                if(s[i+1]==')'){
                    i++;
                    temp+='o';
                }else{
                    temp+="al";
                    i+=3;
                }
            }
        }
        
        return temp;
        
    }
};