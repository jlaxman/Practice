class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int> > dist(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++) dist[i][i]=0;
        for(auto e: edges){
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][j]> dist[i][k]+ dist[k][j])
                    {
                        dist[i][j]= dist[i][k]+ dist[k][j];
                    }
                    
                        
                }
                        
            }
        }
        int mincnt=INT_MAX;
        int actualcity=0;
        for(int i=0; i<n; i++){
            int cnt=0;
            int city=i;
            for(int j=0; j<n; j++){
                if(j!=i && dist[i][j]<= dt){
                    cnt++;
                }
            }
            if(cnt<= mincnt){
                mincnt=cnt;
                actualcity=city;
            }
        }
        return actualcity;
        
        
        
        
    }
           
    
};