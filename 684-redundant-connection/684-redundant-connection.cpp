class Solution {
   class dsu{
        int n;
        vector<int> parent;
        vector<int> rank;
    public:
        dsu(int n){
            this->n=n;
            parent.resize(n, -1);
            rank.resize(n, 1);
        }
        int find_set(int i){
            if(parent[i]==-1) return i;
            else return parent[i]=find_set(parent[i]);
        }
        void union_set(int i, int j){
            int s1= find_set(i);
            int s2=find_set(j);
            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    rank[s2]+=rank[s1];
                    parent[s2]=s1;
                }else{
                    rank[s1]+=rank[s2];
                    parent[s1]=s2;
                }
            }
        }
        bool givp(){
            int cnt=0;
           for(int i=1; i<n; i++){
               if(parent[i]==-1) cnt++;
           }
        
       return cnt==1;
     }
        
        
        
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
          dsu d(n+1);
        for(int i=0; i<n; i++){
            int j=i;
            int x=edges[j][0];
            int y=edges[j][1];
            int s1= d.find_set(x);
            int s2= d.find_set(y);
            if(s1!=s2){
                d.union_set(x, y);
            }else return edges[j];
                  
        }
        return {};
        
    }
};