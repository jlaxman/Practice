class Solution {
    class dsu{
        int n;
        vector<int> parent, rank;
    public:
        
        dsu(int n){
            this->n=n;
            parent.resize(n, -1);
            rank.resize(n, 1);
        }
       int find_set(int i){
           if(parent[i]==-1) return i;
           return parent[i]= find_set(parent[i]);
       }
        
        void union_set(int i, int j){
            int s1=find_set(i);
            int s2=find_set(j);
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
            for(auto p: parent){
                if(p==-1) cnt++;
            }
            return cnt==1;
        }
        
    };
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        dsu g(n+1);
        vector<vector<int>> edges=pipes;
       for(int i=1; i<=n; i++){
           edges.push_back({0, i, wells[i-1]});
       }
        auto comp=[](auto& x, auto& y){
            return x[2]<y[2];
        };
       sort(edges.begin(), edges.end(),comp);
        int ans=0;
        for(auto e: edges){
            int s1= g.find_set(e[0]);
            int s2=g.find_set(e[1]);
            
                if(s1!=s2){
                    g.union_set(e[0], e[1]);
                    ans+=e[2];
                }
        }
        return ans;
            
    }
        
    
};