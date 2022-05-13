/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
       
        Node* curr=root;
        while(curr!=NULL){
            
        
            Node* temp= new Node(0);
            Node* nextfirst=NULL;
                while(curr!=NULL){
                   if(curr->left!=NULL && nextfirst==NULL){
                       nextfirst=curr->left;
                   }
                   if(curr->right!=NULL && nextfirst==NULL){
                       nextfirst=curr->right;
                   }
                    if(curr->left!=NULL){
                        temp->next= curr->left;
                        temp=temp->next;
                    }
                     if(curr->right!=NULL){
                        temp->next= curr->right;
                        temp=temp->next;
                    }
                    curr=curr->next;
                 }
            curr=nextfirst;
            
        }
        return root;
        
        
//         queue<Node* > q;
//         q.push(root);
       
//         while(!q.empty()){
//             int sz= q.size();
//             for(int i=0; i<sz; i++){
//                 Node* currNode= q.front();
//                 q.pop();
//                 if(i!=sz-1) currNode->next= q.empty()? NULL: q.front();
//                 if(currNode->left!=NULL)  q.push(currNode->left);
//                 if(currNode->right!=NULL) q.push(currNode->right);
                
//             }
//         }
//         return root;
        
    }
};