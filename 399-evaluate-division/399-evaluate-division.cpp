class Solution {
public:
    double an=1.0;
    double rp=1.0;
    
    
    bool dfs(string in, string out,  unordered_map<string, vector<pair<string, double> >> adj,  unordered_map<string, int> vis){
        if(in==out && adj.find(out)!=adj.end()){
            
            return true;
            
        }
        vis[in]=1;
        for(auto a: adj[in]){
            if(vis[a.first]==0){
                if(dfs(a.first, out, adj, vis)==true){
                    rp*=a.second;
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
     unordered_map<string, vector<pair<string, double> > > adj;
    
     for(int i=0; i<equations.size(); i++){
         string in=equations[i][0];
         string out=equations[i][1];
         double val= (1.0/(1.0*values[i]));
         adj[in].push_back(make_pair(out, 1.0*values[i]));
         adj[out].push_back(make_pair(in, val));
         
     }
        vector<double> ans;
     for(auto v: queries){
        string in=v[0];
        string out= v[1];
        unordered_map<string, int> vis;
         an=1.0;
         rp=1.0;
        bool path=dfs(in, out, adj, vis);

        if(path) ans.push_back(rp);
        else ans.push_back(-1);
     }
        
    
    return ans;
    }
    
    
    
};