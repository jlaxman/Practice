class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
    vector<int> dist(n, 1e9);
    dist[src]=0;
    vector<int> temp(dist.begin(), dist.end());
    for(int l=0; l<=k; l++){
       
        for(auto e: flights){
            if(dist[e[0]]!=1e9 && temp[e[1]]> dist[e[0]]+ e[2]){
               temp[e[1]]= dist[e[0]]+ e[2];
            }
        }
        dist=temp;
    }
    return dist[dst]==1e9? -1 : dist[dst];
        
    }
};