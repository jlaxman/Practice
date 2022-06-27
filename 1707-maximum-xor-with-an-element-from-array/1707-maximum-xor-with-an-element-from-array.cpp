class Solution {
public:
    class Node{
    public:
        Node* zero;
        Node* one;
        Node(){
            zero=NULL;
            one=NULL;
        }
    };
    Node* root;
    void insert(int n){
        Node* curr=root;
        for(int i=31; i>=0;i--){
            if(n&(1<<i)){
                if(curr->one==NULL){
                    curr->one =new Node();
                }
                curr=curr->one;
            }else{
                 if(curr->zero==NULL){
                    curr->zero =new Node();
                }
                curr=curr->zero;
            }
        }
    }
     int maxXor(int n){
        Node* curr=root;
        bitset<32> bs(n);
        int ans=0;
        int path=0;
        for(int j=31; j>=0; j--){
            if(bs[j]==1){
                if(curr->zero){
                    curr=curr->zero;
                    ans+= (1<<j);
                }else{
                    curr=curr->one;
                }
                
            }else{
                if(curr->one){
                    curr=curr->one;
                    ans+= (1<<j);
                }else{
                    curr=curr->zero;
                }
                
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root= new Node();
        int n=queries.size();
        int ml=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> q;
        int i=0;
        for(auto query: queries){
            q.push_back({query[1], query[0], i});
            i++;
        }
        sort(q.begin(), q.end());
        vector<int> ans(queries.size(), 0);
        i=0;
        int j=0;
        while(i<n){
            int m=q[i][0];
            int x=q[i][1];
            if(m<nums[0]){
                ans[q[i][2]]=-1;
                i++;
                continue;
            }
            while(j<ml && nums[j]<=m){
                insert(nums[j]);
                j++;
            }
            ans[q[i][2]]= maxXor(x);
            i++; 
        }
        return ans;
        
        
    }
};