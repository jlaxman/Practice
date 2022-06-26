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
     vector<int> inTime, outTime, subtreeXor;
    int currTime;
    void dfs(int curr, int par, vector<vector<int>> &adj, vector<int>& a) {
        inTime[curr] = ++currTime;
        subtreeXor[curr] = a[curr];
        for(auto child : adj[curr]) {
            if(child != par) {
               dfs(child, curr, adj, a);
               subtreeXor[curr] ^= subtreeXor[child];
            }
        }

        outTime[curr] = ++currTime;
    }
    bool sameSubtree(int a, int b) {
        return (inTime[a] < inTime[b]) && (outTime[b] < outTime[a]);
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        currTime = 0;
        inTime.resize(n, -1);
        outTime.resize(n, -1);
        subtreeXor.resize(n, 0);
        vector<vector<int>> adj(nums.size());
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // vector<int> pre(nums.size(), 0), post(nums.size(), 0), subXor(nums.size(), 0);
        // vector<int> vis(nums.size(), 0);
        // dfs(0, 0, pre, post, adj, subXor, vis, nums);
        dfs(0, -1, adj, nums);
        int minScore=INT_MAX;
        for(int i=1; i<nums.size(); i++){
             for(int j=i+1; j<nums.size(); j++){
                  vector<int> a(3, 0);
                  a[0]= subtreeXor[i];
                  a[1]= subtreeXor[j];
                 if(sameSubtree(i, j)){
                    a[0]^=a[1];
                 }else if(sameSubtree(j, i)){
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
// class Solution {
// public:
//     vector<int> inTime, outTime, subtreeXor;
//     int currTime;
//     void dfs(int curr, int par, vector<vector<int>> &adj, vector<int>& a) {
//         inTime[curr] = ++currTime;
//         subtreeXor[curr] = a[curr];
//         for(auto child : adj[curr]) {
//             if(child != par) {
//                dfs(child, curr, adj, a);
//                subtreeXor[curr] ^= subtreeXor[child];
//             }
//         }

//         outTime[curr] = ++currTime;
//     }
//     bool sameSubtree(int a, int b) {
//         return (inTime[a] <= inTime[b]) && (outTime[b] <= outTime[a]);
//     }
//     int minimumScore(vector<int>& a, vector<vector<int>> &ed){
//         int n = a.size();
//         currTime = 0;
//         inTime.resize(n, -1);
//         outTime.resize(n, -1);
//         subtreeXor.resize(n, 0);
//         vector<vector<int>> v(n);
//         for(auto &x: ed){
//             v[x[0]].push_back(x[1]);
//             v[x[1]].push_back(x[0]);
//         }
//         dfs(0, -1, v, a);
//         int xorTree = subtreeXor[0];
//         int ans = INT_MAX;
//         for(int i = 1; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 int a, b, c;

//                 if(!sameSubtree(i, j) && !sameSubtree(j, i)) {
//                     a = subtreeXor[i], b = subtreeXor[j];
//                 } else if(sameSubtree(i, j)) {
//                     a = subtreeXor[j], b = (a ^ subtreeXor[i]);
//                 } else if(sameSubtree(j, i)) {
//                     a = subtreeXor[i], b = (a ^ subtreeXor[j]);
//                 }

//                 c = (xorTree ^ a ^ b);
//                 ans = min(ans, max({a, b, c}) - min({a, b, c}));
//             }
//         }
//         return ans;
//     }
// };