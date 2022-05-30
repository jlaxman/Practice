class Solution {
    
 struct segment_tree{
     int n;
     vector<int> st;
     void init(int n){
         this->n=n;
         st.resize(4*n, 0);
     }
     void build(int i, int j, vector<int>& arr, int node){
         if(i==j){
             st[node]=arr[i];
             return ;
         }
         int mid= (i+j)/2;
         build(i, mid, arr, 2*node+1);
         build(mid+1, j, arr, 2*node+2);
         st[node]= st[2*node+1] ^ st[2*node+2];
         return ;
         
     }
     void build(vector<int>& arr){
         
         build(0, n-1, arr, 0);
     }
     int query(int l, int r, int start, int end, int node){
         if(l>end || r< start)  return 0;
         
         if(start>=l && end<=r){
             return st[node];
         }
         int mid= (start+end)/2;
         int q1=query(l, r, start, mid, 2*node+1);
         int q2=query(l, r, mid+1, end, 2*node+2);
         return q1^q2;
         
         
         
     }
     
     int query(int l, int r){
         return query(l, r, 0, n-1, 0);
     }
     
     
     
 };
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        segment_tree tree;
        tree.init(arr.size());
        tree.build(arr);
        for(auto q: queries){
            ans.push_back(tree.query(q[0], q[1]));
        }
        // for(int i=0; i<4*arr.size(); i++){
        //     cout<< tree.st[i]<<" ";
        // }
        
        return ans;
        
    }
};