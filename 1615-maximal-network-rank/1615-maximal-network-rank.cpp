class Solution {
public:
    int N;
    int score(int i, int j, vector<vector<int>>& graph, vector<int>& deg){
        int ans=0;
        ans= deg[i]+deg[j];
        if(graph[i][j]){
            ans--;
        }
        return ans;
   }
    int maximalNetworkRank(int n, vector<vector<int>> roads) {
        N=n;
        int ans=0;
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<int> deg(n, 0);
       
        for(auto road: roads){
            graph[road[0]][road[1]]=1;
            graph[road[1]][road[0]]=1;
            deg[road[0]]++;
            deg[road[1]]++;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans=max(ans, score(i, j, graph, deg));
            }

        }
        return ans;

  }
};