class Solution {
    
    bool check(int x, int y, int n){
        return (x>=0 &&  x<n && y>=0 && y<n);
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int dx[8]={1, 1, -1, -1, 0, 0, 1, -1};
        int dy[8]={1, -1, 1, -1, 1, -1, 0, 0};
        visited[0][0]=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0; i<sz; i++){
                auto curr=q.front();
                q.pop();
                int x= curr.first;
                int y=curr.second;
                for(int k=0; k<8; k++){
                    if(check(x+dx[k], y+dy[k], n) && grid[x+dx[k]][y+dy[k]]==0 && visited[x+dx[k]][y+dy[k]]==0){
                        visited[x+dx[k]][y+dy[k]]=visited[x][y]+1;
                        q.push(make_pair(x+dx[k], y+dy[k]));
                    }
                }
                
            }
        }
        if(visited[n-1][n-1]==0 && n!=1) return -1;
        return visited[n-1][n-1]+1;
        
    }
};