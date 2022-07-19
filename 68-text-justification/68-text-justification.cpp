class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int mW) {
        
        vector<string> ans;
         string s;
        for(int i=0; i<words.size(); i++){
           
            
            if(words[i].size()+s.size()>mW){
                string res;
                s.pop_back();
                stringstream sk(s);
                string word;
                int cnt=0;
                while(sk>>word){
                    cnt++;
                }
                if(cnt==1){
                    int sz=s.size();
                    for(int k=sz; k<mW; k++){
                        s+=' ';
                    }
                    ans.push_back(s);
                    s.clear();
                    s+=words[i];
                    s+=' ';
                    continue;
                    
                }
                int rem= mW-s.size();
                int rs=rem%(cnt-1);
                int ns=rem/(cnt-1);
                
                stringstream ss(s);
                
                while(ss>>word){
                    res+=word;
                    if(res.size()==mW) break;
                    res+=' ';
                    for(int k=0; k<ns; k++){
                        res+=' ';
                    }
                    if(rs>0){
                        res+=' ';
                        rs--;
                    }
                }
                // while(res.size()>mW){
                //     res.pop_back();
                // }
                ans.push_back(res);
                s.clear();   
            }
            s+=words[i];
            s+=' ';
              
        }
        if(s.size()){
            s.pop_back();
            int sz=s.size();
            for(int i=sz; i<mW; i++){
                s+=' ';
            }
            ans.push_back(s);
        }
        return ans;
        
        
        
        
    }
};