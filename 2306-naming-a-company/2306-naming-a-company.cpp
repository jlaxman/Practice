class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> start(26);
        for(auto & idea: ideas){
            start[idea[0]-'a'].insert(idea.substr(1));
        }
        long long ans=0;
        for(int i=0; i<26; i++){
            for(int j=i+1; j<26; j++){
                long long c1=0;
                long long c2=0;
                auto st1= start[i];
                auto st2= start[j];
                for(auto s: st1){
                    if(start[j].find(s)==start[j].end()){
                        c1++;
                    }
                }
                for(auto s: st2){
                    if(start[i].find(s)==start[i].end()){
                        c2++;
                    }
                }
                ans+=(c1*c2);  
                
            }
        }
        return 2*ans;
        
    }
};