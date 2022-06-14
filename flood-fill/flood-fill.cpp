class Solution {

public:
    bool check(int x,int y, int m, int n){
        return (x>=0 && y>=0 && x<m && y<n);
    }
    void dfs(int i, int j, int m, int n, vector<vector<int>>& image, int color){
        int v=image[i][j];
        image[i][j]=color;
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, 1, -1};
        for(int k: {0, 1, 2, 3}){
            int x= i+dx[k];
            int y= j+dy[k];
            if(check(x, y, m, n) && image[x][y]==v){
                dfs(x, y, m, n, image, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color== image[sr][sc]) return image;
        dfs(sr, sc, image.size(), image[0].size(), image, color);
        return image;
        
    }
};