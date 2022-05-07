class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>> edges) {
        int mini=INT_MAX;
        vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
        vector<int> deg(n+1, 0);
        for(auto edge: edges){
            graph[edge[0]][edge[1]]=1;
            graph[edge[1]][edge[0]]=1;
            deg[edge[0]]++;
            deg[edge[1]]++;

        }


        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                for(int k=j+1; k<=n; k++){
                    if(graph[i][j] && graph[j][k] && graph[k][i]){
                        mini=min(mini, deg[i]+deg[j]+deg[k]-6);
                    }
                }
            }
        }
        if(mini==INT_MAX) return -1;
        else return mini;
 
   }
};