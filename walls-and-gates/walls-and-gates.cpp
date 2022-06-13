class Solution {
    
public:
    bool check(int m , int n, int x, int y){
        
        return x>=0 && x<m && y>=0 && y<n;
    }
    void bfs(int i, int j, vector<vector<int>>& rooms, int m, int n){
       queue<pair<int,int>> q;
       q.push({i, j});
        
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, 1, -1};
        int steps=0;
      while(!q.empty()){
          int sz=q.size();
          for(int k=0; k<sz; k++){
              int ix= q.front().first;
              int jy= q.front().second;
              q.pop();
              
              for(int nbr: {0, 1, 2, 3}){
                  int x= ix+dx[nbr];
                  int y= jy+dy[nbr];
                  if(check(m, n, x, y)  && rooms[x][y]> rooms[ix][jy]+1 ){
                      rooms[x][y]=rooms[ix][jy]+1;
                      q.push({x, y});
                  }   
                  
              }
               
          }  
      }
        return ;
        
        
        
    
    
    
    
    
    
    
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        int m=rooms.size();
        int n=rooms[0].size();
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(rooms[i][j]==0){ 
                    bfs(i, j, rooms, m, n);
                }
                   
            }
        }
        return ;
        
        
        
        
        
        
        
        
    }
};