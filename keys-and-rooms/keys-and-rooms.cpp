class Solution {
    void dfs(int i, int n, vector<vector<int>>& rooms, vector<int>& vis){
        vis[i]=1;
        for(auto nbr: rooms[i]){
            if(vis[nbr]==0){
                dfs(nbr, n, rooms, vis);
            }
        }
        return ;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n, 0);
        dfs(0, n, rooms, vis);
        for(int i=0; i<n; i++){
            if(vis[i]==0) return 0;
        }
        return 1;
        
    }
};