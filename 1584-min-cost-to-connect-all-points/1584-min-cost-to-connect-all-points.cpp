class Solution {
    
int dist(vector<int>& p1, vector<int>& p2){
    return abs(p1[0]-p2[0])+ abs(p1[1]-p2[1]);
}
int find_set(int i, vector<int>& parent){
    if(parent[i]==-1) return i;
    else return parent[i]=find_set(parent[i], parent);
}

void union_set(int i, int j, vector<int>& parent, vector<int>& rank){
    int s1= find_set(i, parent);
    int s2= find_set(j, parent);
    
    if(s1!=s2){
        if(rank[s1]<rank[s2]){
            rank[s2]+=rank[s1];
            parent[s1]=s2;
        }else{
            rank[s1]+= rank[s2];
            parent[s2]=s1;
        }
    }
    return ;
}
public:
   int minCostConnectPoints(vector<vector<int>>& ps) {
       int n=ps.size();
       vector<vector<int>> edges;
       for(int i=0; i<n; i++){
           for(int j=i+1; j<n; j++){
               edges.push_back({abs(ps[i][0]-ps[j][0])+ abs(ps[i][1]-ps[j][1]), i, j});
           }
       }
       sort(edges.begin(), edges.end());
       int ans=0;
       vector<int> parent(n, -1);
       vector<int> rank(n, 1);
       for(auto e: edges){
           int x=e[1];
           int y=e[2];
           int w=e[0];
           int s1= find_set(x, parent);
           int s2= find_set(y, parent);
           if(s1!=s2){
               ans+=w;
               union_set(x, y, parent, rank);
           }
       }
       return ans;
   
       
}
};