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
    bool check(TreeNode* root, long long l, long long r){
        if(!root) return true;
        
        return (root->val> l) && (root->val <r) && check(root->left, l, root->val) && check(root->right, root->val, r);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long l=LONG_MIN;
        long long r=LONG_MAX;
        return check(root, l, r);
    }
};