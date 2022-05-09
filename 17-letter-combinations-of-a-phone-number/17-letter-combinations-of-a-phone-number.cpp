class Solution {
    
    
public:
    void fun(int i, string& d, string& temp, vector<string>& vec, unordered_map<int, vector<char> > mpp){
        if(i==d.size()){
            vec.push_back(temp);
            return;
        }
        for(auto ch: mpp[d[i]-'0']){
            temp+= ch;
            fun(i+1, d, temp, vec, mpp);
            temp.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string d) {
       unordered_map<int, vector<char> >mpp;
        for(int i=2; i<=9; i++){
            if(i<=6){
                for(int k=(i-2)*3; k<(i-2)*3 +3; k++){
                    mpp[i].push_back('a'+k);
                }
            }else{
                if(i==7){
                   mpp[i].push_back('p'); 
                   mpp[i].push_back('q'); 
                   mpp[i].push_back('r'); 
                   mpp[i].push_back('s'); 
                }
                if(i==8){
                   mpp[i].push_back('t'); 
                   mpp[i].push_back('u'); 
                   mpp[i].push_back('v'); 
                   
                }
                if(i==9){
                   mpp[i].push_back('w'); 
                   mpp[i].push_back('x'); 
                   mpp[i].push_back('y'); 
                   mpp[i].push_back('z');
                }
            }
            
        }
        if(d.size()==0) return {};
        vector<string> vec;
        string temp;
        fun(0, d, temp, vec, mpp);
        return vec;
    }
};