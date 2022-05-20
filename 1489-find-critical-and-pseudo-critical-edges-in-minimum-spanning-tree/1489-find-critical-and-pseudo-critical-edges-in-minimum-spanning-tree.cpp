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
        for(int i=0; i<n; i++){
            if(parent[i]==-1) cnt++;
        }
        return cnt==1;
    }

        
};

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& e) {
     vector<vector<int>> edges=e;
        unordered_map<int, int> mpp;
    int k=0;
    for(auto edge: edges){
        mpp[edge[0]+(edge[1]*n)]=k++;
    }
    auto comp=[](auto& x, auto& y){
         return x[2]<y[2];
    };
    sort(edges.begin(), edges.end(), comp);
     dsu a(n);
        int ans=0;
    for(int i=0; i<edges.size(); i++){
        
       int s1=a.find_set(edges[i][0]);
        int s2= a.find_set(edges[i][1]);
        if(s1!=s2){
            ans+=edges[i][2];
            a.union_set(edges[i][0], edges[i][1]);
        }
        
        

    }
    cout<< ans<<endl;
    if(a.connected()==false) return {{}};
    vector<int> vec, vec1;
    for(int j=0; j<edges.size(); j++){
        dsu c(n);
        int ans1=0;
        for(int i=0; i<edges.size() ; i++){
            
            if(i==j) continue;
            int s1= c.find_set(edges[i][0]);
            int s2= c.find_set(edges[i][1]);
            if(s1!=s2){
                ans1+=edges[i][2];
                c.union_set(edges[i][0], edges[i][1]);
            }
        }
        if(c.connected()==false || ans1>ans) vec.push_back(mpp[edges[j][0]+(edges[j][1]*n)]);
        else{
            dsu b(n);
            b.union_set(edges[j][0], edges[j][1]);
            int ans2=edges[j][2];
            for(int i=0; i<edges.size(); i++){
                if(i==j) continue;
                int s1= b.find_set(edges[i][0]);
                int s2= b.find_set(edges[i][1]);
                if(s1!=s2){
                    ans2+=edges[i][2];
                    b.union_set(edges[i][0], edges[i][1]);
                }
            }
            if(ans2==ans) vec1.push_back(mpp[edges[j][0]+(edges[j][1]*n)]);
        }
    }
    vector<vector<int>> res;
    res.push_back(vec);
    res.push_back(vec1);
    return res;
        
        

    }
        
};