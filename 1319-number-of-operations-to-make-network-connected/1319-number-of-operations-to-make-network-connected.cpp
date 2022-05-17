class Solution {
    
int find_set(int i, vector<int>& parent){
    if(parent[i]==-1) return i;
    else return parent[i]= find_set(parent[i], parent);
}
void union_set(int i, int j, vector<int>& parent, vector<int>& rank){
    int s1=find_set(i, parent);
    int s2= find_set(j, parent);
    if(s1!=s2){
        if(rank[s1]< rank[s2]){
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }else{
            parent[s2]=s1;
            rank[s1]+=rank[s2];
        }
    }
    return ;
}
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        int extra=0;
        vector<int> parent(n, -1), rank(n, 1);
        for(auto v :conn){
            int a=v[0];
            int b=v[1];
            int s1= find_set(a, parent);
            int s2= find_set(b, parent);
            if(s1==s2) extra++;
            else{
                union_set(a,b, parent, rank);
            }
        }
        int c=0;
        for(int i=0; i<n; i++){
            if(parent[i]==-1) c++;
            cout<<parent[i]<<" ";
            
        }
        if(extra>= c-1) return max(c-1, 0);
        else return -1;
        
    }
};