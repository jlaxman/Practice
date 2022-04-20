class Solution {

public:
    int fun(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, +1, -1};
        int ans=0;
        for(int k=0; k<4; k++){
            int a=0;
            if(i+dx[k]>=0 && i+dx[k]<grid.size() && j+dy[k]>=0 && j+dy[k]<grid[0].size() && !visited[i+dx[k]][j+dy[k]]){
                visited[i+dx[k]][j+dy[k]]=1;
                if(grid[i+dx[k]][j+dy[k]]>0) a=grid[i+dx[k]][j+dy[k]]+fun(i+dx[k], j+dy[k], grid, visited);
                ans=max(a, ans);
                visited[i+dx[k]][j+dy[k]]=0;
            }
        }
        return ans;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<pair<int, int> >vec;
        int i=0;
        int j=0;
        for(auto r: grid){
            
            for(auto v: r){
                if(v!=0){
                    vec.push_back(make_pair(i, j));
                }
                j++;
            }
            i++;
            j=0;
        }
        int mx=INT_MIN;
        for(auto p: vec){
            vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
            visited[p.first][p.second]=1;
            int ans=grid[p.first][p.second]+fun(p.first, p.second, grid, visited);
            
            mx=max(ans, mx);
        }
        return mx==INT_MIN? 0: mx;
        
    }
};