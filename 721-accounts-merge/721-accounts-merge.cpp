class Solution {
public:
     unordered_map<string, vector<string>> mpp;
     unordered_set<string> vis;
    void dfs(string s, vector<string>& vec){
        vis.insert(s);
        vec.push_back(s);
        for(auto nbr: mpp[s]){
            if(vis.find(nbr)==vis.end()){
                dfs(nbr, vec);
            }
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       
        for(auto acc: accounts){
            string name= acc[0];
            string fp= acc[1];
            for(int j=2; j<acc.size(); j++){
                mpp[acc[1]].push_back(acc[j]);
                 mpp[acc[j]].push_back(acc[1]);
            }
       }
        vector<vector<string>> res;
        for(auto acc: accounts){
            string name= acc[0];
            string fp= acc[1];
            
            if(vis.find(fp)==vis.end()){
                vector<string> vec;
                vec.push_back(name);
                dfs(fp, vec);
                sort(vec.begin()+1, vec.end());
                res.push_back(vec); 
            }
       }
        return res;
       
        
        
    }
};