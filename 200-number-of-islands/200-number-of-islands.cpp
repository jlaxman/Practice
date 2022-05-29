class Solution {
public:
    bool check(int i, int j, int m, int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
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
        vector<int> givp(){
            return parent;
        }
        
        
        
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, 1, -1};
        int m=grid.size();
        int n=grid[0].size();
        dsu d(m*n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    for(int k: {0, 1, 2, 3}){
                        int x= i+dx[k];
                        int y= j+dy[k];
                        if(check(x, y, m, n) && grid[x][y]=='1'){
                            int s1= d.find_set(i*n +j);
                            int s2= d.find_set(x*n+y);
                            if(s1!=s2){
                               d.union_set(i*n+j, x*n+y); 
                            }
                        }
                    }
                }
                
            }
        }
        vector<int> par=d.givp();
        int cnt=0;
        for(int i=0; i<m*n; i++){
            if(grid[i/n][i%n]=='1' && par[i]==-1) cnt++;
        }
        
        
         
        return cnt;
        
    }
};