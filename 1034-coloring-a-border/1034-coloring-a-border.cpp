class Solution {
public:
    bool check(int x, int y, int m, int n){
        return (x>=0 && x<m && y>= 0 && y<n);
    }
    bool insidecheck(int i, int j, vector<vector<int>>& grid, int m, int n){
        
        if(i==0 || i==m-1 || j==0 || j==n-1) return false;
        
        if(i-1>=0 && abs(grid[i-1][j])!=abs(grid[i][j])){
            return false;
        }
        if(i+1<m && abs(grid[i+1][j])!=abs(grid[i][j])){
            return false;
        }
        if(j-1>=0 && abs(grid[i][j-1])!=abs(grid[i][j])){
            return false;
        }
        if(j+1<n && abs(grid[i][j+1])!=abs(grid[i][j])){
            return false;
        }
        return true;
    }
    
public:
    
    void dfs(int i, int j, vector<vector<int>>& grid, int m, int n){
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, 1, -1};
        grid[i][j]*=-1;
        for(int k=0; k<4; k++){
            int x= i+dx[k];
            int y= j+dy[k];
            if(check(x, y, m, n) && grid[x][y]== -grid[i][j]){
                dfs(x, y, grid, m, n);
            }
        }
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        // if(grid[row][col]==color) return grid;
        
        int m=grid.size();
        int n=grid[0].size();
        dfs(row, col, grid, m, n);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]<0){
                    if(insidecheck(i, j, grid, m, n)){
                        grid[i][j]*=-1;
                    }
                }
            }
        }
        
         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]<0) grid[i][j]=color;
            }
         }
        return grid;
    }
};