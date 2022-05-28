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
    int mx=INT_MIN;
    int maxpathSum(TreeNode* root) {
        if(!root) return 0;
        int leftsum=maxpathSum(root->left);
        int rightsum= maxpathSum(root->right);
        mx= max(root->val+leftsum+rightsum, mx);
        return max(0,root->val+max(leftsum, rightsum));
        
    }
public:
    int maxPathSum(TreeNode* root) {
        mx=INT_MIN;
        
        maxpathSum(root);
        return mx;
        
    }
};