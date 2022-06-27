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
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        for(auto n: nums){
            insert(n);
        }
        int ans=0;
        for(auto n: nums){
            ans=max(ans, maxXor(n));
        }
        return ans;  
    }
    int maxXor(int n){
        Node* curr=root;
        bitset<32> bs(n);
        int ans=0;
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
};