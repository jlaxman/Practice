class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto t: times){
            adj[t[0]].push_back(make_pair(t[2], t[1]));
        }
       queue<int> q;
        vector<int>  dist(n+1, 1e9);
        dist[k]=0;
        dist[0]=0;
        q.push(k);
        while(!q.empty()){
           auto p=q.front();
           q.pop();
            for(auto nbr: adj[p]){
                if(dist[nbr.second]> nbr.first+ dist[p]){
                    dist[nbr.second]=nbr.first+ dist[p];
                    q.push(nbr.second);
                }
                
            }
          
        }
        int ans=*max_element(dist.begin(), dist.end());
        if(ans==1e9) return -1;
        else return ans;
       
        
    }
};