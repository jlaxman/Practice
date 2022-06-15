class Solution {
public:
    bool check(int x, int y,int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n=mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, 1, -1};
       
        auto ans=mat;
        int d=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0; i<sz; i++){
                auto curr=q.front();
                q.pop();
                for(int k: {0, 1, 2, 3}){
                    int x=curr.first+dx[k];
                    int y= curr.second+dy[k];
                    if(check(x, y, m, n) && mat[x][y]==1 && vis[x][y]==0){
                        ans[x][y]= d;
                        vis[x][y]=1;
                        q.push({x, y});
                    }
                }
                
            }
            d++;
            
        }
        return ans;
        
        
    }
};