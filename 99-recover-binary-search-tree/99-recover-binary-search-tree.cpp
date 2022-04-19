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
    TreeNode* temp=NULL;
    int prev=INT_MIN;
public:
    void recoverTree(TreeNode* root) {
        TreeNode* r1= NULL;
        TreeNode* r2= NULL;
        inorder(root, r1,  r2);
        r1->val= r1->val^r2->val;
        r2->val= r2->val^ r1->val;
        r1->val= r2->val^ r1->val;
        
        return ;
    }
public:
    void inorder(TreeNode* root, TreeNode*& r1, TreeNode*& r2){
        if(!root) return ;
        inorder(root->left, r1, r2);
        if (temp != NULL && root->val < temp->val) {
           r2 = root;
          if (r1 == NULL) r1 = temp;
          else return;
        }
        temp= root;
        inorder(root->right, r1, r2);
        return ;
        
    }
};