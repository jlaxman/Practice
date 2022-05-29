class Solution {
private:
    unordered_map<string, vector<string>> adj;
    unordered_set<string> st;
    
public:
    void dfs(string s, vector<string>& vec){
        st.insert(s);
        vec.push_back(s);
        for(auto nbr: adj[s]){
            if(st.find(nbr)==st.end()){
                dfs(nbr, vec);
            }
        }
        
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        
        for(auto a: acc){
            string first=a[1];
            for(int i=2; i<a.size(); i++){
                adj[first].push_back(a[i]);
                adj[a[i]].push_back(first);
            }
        }
        vector<vector<string>> ans;
        for(auto a: acc){
            string name=a[0];
            string first= a[1];
            
            if(st.find(a[1])==st.end()){
                vector<string> vec;
                vec.push_back(name);
                dfs(a[1],  vec);
                sort(vec.begin()+1, vec.end());
                ans.push_back(vec);
            }
        }
        return ans;
        
    }
};