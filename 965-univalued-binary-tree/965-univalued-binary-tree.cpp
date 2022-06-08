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
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return 1;
        int right=1;
        int left=1;
        if(root->left){
            if(root->left->val== root->val){
                left=isUnivalTree(root->left);
            }else return 0;
        }
         if(root->right){
            if(root->right->val== root->val){
                right=isUnivalTree(root->right);
            }else return 0;
        }
        
        return left*right;
    }
};