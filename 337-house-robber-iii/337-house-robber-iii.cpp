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
private:
    unordered_map<TreeNode*, int> mpp;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(mpp[root]!=0) return mpp[root];
        int op1=rob(root->left)+rob(root->right);
        int op2= root->val;
        if(root->left){
            op2+= rob(root->left->left);
            op2+= rob(root->left->right);
            
        }
        if(root->right){
            op2+= rob(root->right->left);
            op2+= rob(root->right->right);
        }
        return mpp[root]=max(op1, op2);
    }
};