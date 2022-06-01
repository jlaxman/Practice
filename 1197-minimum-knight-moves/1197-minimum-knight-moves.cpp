class Solution {
public:
    bool check(int x, int y){
        return (x>=0 && y>=0 && x<=600 && y<=600);
    }
public:
    int minKnightMoves(int x, int y) {
        
        vector<vector<int>> dist(601, vector<int>(601, -1));
        int X=x+300;
        int Y= y+300;
        dist[300][300]=0;
        queue<pair<int, int>> q;
        q.push({300, 300});
        int dx[8]={2, -2, 2, -2, 1, -1, 1, -1};
        int dy[8]={1, -1, -1, 1, 2, -2, -2, 2};
        while(q.size()){
            auto p=q.front();
            q.pop();
            int nx= p.first;
            int ny= p.second;
            if(nx==X && ny==Y) break;
            for(int k=0; k<8; k++){
                if(check(nx+dx[k], ny+dy[k]) && dist[nx+dx[k]][ny+dy[k]]==-1){
                    dist[nx+dx[k]][ny+dy[k]]= dist[nx][ny]+1;
                    q.push({nx+dx[k], ny+dy[k]});
                }
            }      
        }
        return dist[X][Y];
    }
};