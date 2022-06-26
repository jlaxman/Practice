class Solution {
public:
//     void dfs(int s, int time, vector<int>& pre, vector<int>& post, vector<vector<int>>& adj, vector<int>& subXor, vector<int>& vis, vector<int>& nums){
//       vis[s]=1;
//       pre[s]=time;
//       time++;
//       subXor[s]=nums[s];
//       for(auto nbr : adj[s]){
//           if(vis[nbr]==0){
//               dfs(nbr, time, pre, post, adj, subXor, vis, nums);
//                subXor[s]^=subXor[nbr];
//           }
//       }
//      post[s]=time;
//      time++;
        
//       return ;
        
//     }
// bool sameSubtree(int i, int j, vector<int>& pre, vector<int>& post){
//     return ((pre[j]>pre[i]) && (post[j]<post[i]));
// }
    //  vector<int> inTime, outTime, subtreeXor;
    // int currTime;
    void dfs(int curr, int& currTime, vector<int>& inTime, vector<int>& outTime, vector<int>& subtreeXor, vector<int>& vis, vector<vector<int>> &adj, vector<int>& a) {
        inTime[curr] = ++currTime;
        subtreeXor[curr] = a[curr];
        vis[curr]=1;
        for(auto child : adj[curr]) {
            if(vis[child]==0) {
               dfs(child, currTime, inTime, outTime, subtreeXor, vis, adj, a);
               subtreeXor[curr] ^= subtreeXor[child];
            }
        }

        outTime[curr] = ++currTime;
    }
    bool sameSubtree(int a, int b, vector<int>& inTime, vector<int>& outTime) {
        return (inTime[a] < inTime[b]) && (outTime[b] < outTime[a]);
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int currTime = 0;
        // inTime.resize(n, -1);
        // outTime.resize(n, -1);
        // subtreeXor.resize(n, 0);
        vector<vector<int>> adj(nums.size());
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> inTime(nums.size(), 0), outTime(nums.size(), 0), subtreeXor(nums.size(), 0);
        vector<int> vis(nums.size(), 0);
        // dfs(0, 0, pre, post, adj, subXor, vis, nums);
        dfs(0, currTime, inTime, outTime, subtreeXor, vis, adj, nums);
        int minScore=INT_MAX;
        for(int i=1; i<nums.size(); i++){
             for(int j=i+1; j<nums.size(); j++){
                  vector<int> a(3, 0);
                  a[0]= subtreeXor[i];
                  a[1]= subtreeXor[j];
                 if(sameSubtree(i, j, inTime, outTime)){
                    a[0]^=a[1];
                 }else if(sameSubtree(j, i, inTime, outTime)){
                     a[1]^=a[0];
                 }
                 a[2]= subtreeXor[0]^a[0]^a[1];
                 sort(a.begin(), a.end());
                 minScore= min(a[2]-a[0], minScore);
                 // cout<< minScore<<endl;
  
             }
        }
        return minScore;    
    }
};