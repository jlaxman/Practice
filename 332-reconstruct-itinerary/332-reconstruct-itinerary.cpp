class Solution {
    
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> vec;
    
    bool dfs(string s, unordered_map<string, vector<string> > adj, vector<string>& vec, int n, unordered_map<string, int> mpp){
       if(vec.size()==n) return 1;
        
        for(auto nbr: adj[s]){
            string temp=s+'#'+nbr;
            if(mpp[temp]){
                vec.push_back(nbr);
                mpp[temp]--;
                if(dfs(nbr, adj, vec, n, mpp)==true) return true;
                vec.pop_back();
                mpp[temp]++;
            }
            
        }
        return 0;
        
        
    }
    
    void pqdfs(string s){
        while(mp[s].size()){
            string top= mp[s].top();
            mp[s].pop();
            pqdfs(top);
        }
        vec.push_back(s);
        
    }
    
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
//         unordered_map<string, vector<string> > adj;
//         unordered_map<string, int> mpp;
//         for(auto ticket: tickets){
//             string from=ticket[0];
//             string to=ticket[1];
//             adj[from].push_back(to);
//             string temp=from+'#'+to;
//             mpp[temp]++;
//         }
        
//         for(auto dest: adj){
//             auto temp=dest.second;
//             sort(temp.begin(), temp.end());
//             adj[dest.first]=temp;
//             // cout<<t.first<<endl;
//         }
        
//         int n=tickets.size()+1;
//         string temp="JFK";
//         vector<string> vec;
//         vec.push_back("JFK");
//         dfs("JFK", adj, vec, n, mpp);
       for(auto ticket: tickets){
            string from=ticket[0];
            string to=ticket[1];
            mp[from].push(to);
        }
        pqdfs("JFK");
        reverse(vec.begin(), vec.end());
        
        return vec;
        
    }
};