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
    int height(TreeNode* root){
        if(!root) return 0;
        if(mpp[root]!=0) return mpp[root];
        else return mpp[root]=1+ max(height(root->left), height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh= height(root->left);
        int rh= height(root->right);
        return (abs(lh-rh)<=1) && isBalanced(root->left) && isBalanced(root->right);
        
    }
};