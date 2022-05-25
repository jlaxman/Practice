/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 private: TreeNode* prev;
 public: 
    bool inorder(TreeNode* root){
       if(!root) return true;
        
       bool l= inorder(root->left);
      int m=1;
      if(prev!=NULL){
          if(root->val> prev->val){
              prev=root;
          }else m=0;
      }
      if(prev==NULL) prev=root;
      return l && m  && inorder(root->right);
    
    }
public:
    bool isValidBST(TreeNode* root) {
         prev=NULL;
        return inorder(root);
    }
};