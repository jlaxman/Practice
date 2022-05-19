class Solution {
    
    class dsu{
        int n;
        vector<int> parent;
        vector<int> rank;
     public:
        dsu(int n){
            this->n=n;
           parent.resize(n);
           rank.resize(n);
            for(int i=0; i<n; i++){
                parent[i]=-1;
                rank[i]=1;
            }
        }
        int find_set(int i){
            if(parent[i]==-1) return i;
            return parent[i]= find_set(parent[i]);
        }
        void union_set(int i, int j){
            int s1=find_set(i);
            int s2= find_set(j);
            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }else{
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
            
        }
        bool connected(){
            int cnt=0;
            for(int i=1; i<n; i++){
                if(parent[i]==-1) cnt++;
            }
            return cnt==1;
        }
        
        
    };
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu a(n+1);
        dsu b(n+1);
        int remove=0;
        auto comp=[](auto& x, auto& y){
            return x[0]>y[0];
        };
        sort(edges.begin(), edges.end(), comp);
        for(auto e: edges){
            if(e[0]==1){
                int s1= a.find_set(e[1]);
                int s2= a.find_set(e[2]);
                if(s1!=s2){
                    a.union_set(e[2], e[1]);
                }else{
                    remove++;
                }
                
            }else if(e[0]==2){
                
                int s1= b.find_set(e[1]);
                int s2= b.find_set(e[2]);
                if(s1!=s2){
                    b.union_set(e[2], e[1]);
                }else{
                    remove++;
                }
                
            }else {
                int aflag=0, bflag=0;
                int s1= a.find_set(e[1]);
                int s2= a.find_set(e[2]);
                if(s1!=s2){
                    a.union_set(e[2], e[1]);
                }else{
                    aflag=1;
                }
                
                s1= b.find_set(e[1]);
                s2= b.find_set(e[2]);
                if(s1!=s2){
                    b.union_set(e[2], e[1]);
                }else{
                    bflag=1;
                }
                if(aflag && bflag) remove++;
                  
            }
        }
        
        if(a.connected() && b.connected()) return remove;
        else return -1;
        
    }
};