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
TreeNode* temp;
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans= new TreeNode();
        temp=ans;
        fun(root);
        return ans->right;
        
    }
    TreeNode* fun(TreeNode* root ){
        if(!root) return NULL;
    
        fun(root->left);
        root->left=NULL;
         temp->right=root;
        temp=root;
        fun(root->right);
        return root;
    }
        
};