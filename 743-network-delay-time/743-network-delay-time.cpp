class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        
      vector<int> dist(n+1, 1e9);
      set<pair<int, int>> st;
     st.insert({0, k});
        dist[k]=0;
       int maxi=0;
        while(st.size()){
            auto it=st.begin();
            int node=it->second;
            st.erase(it);
            for(auto nbr: adj[node]){
                if(dist[nbr.first]> dist[node]+ nbr.second ){
                    auto f=st.find({dist[nbr.first], nbr.first});
                    if(f!=st.end()){
                        st.erase(f);
                    }
                    
                    dist[nbr.first]=dist[node]+nbr.second;
                    st.insert({dist[nbr.first], nbr.first});
                }
            }
        }
        for(int i=1; i<=n; i++){
            maxi=max(dist[i], maxi);
            cout<< dist[i]<<" ";
        }
        if(maxi==1e9) return -1;
        else return maxi;
       
        
    }
};