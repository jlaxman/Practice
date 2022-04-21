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
class BSTIterator {
public:
    
    TreeNode* it=NULL;
    TreeNode* temp;
   void BSIterator(TreeNode* root){
       if(root==NULL) return ;
        BSIterator(root->left);
        it->right=root;
        it=it->right;
        BSIterator(root->right);
   }
       
    BSTIterator(TreeNode* root) {
      
        temp= new TreeNode();
        it=temp;
        
        BSIterator(root);
    }
    
    int next() {
        temp=temp->right;
        return temp->val;
    }
    
    bool hasNext() {
        
        return temp->right!=NULL? 1: 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */