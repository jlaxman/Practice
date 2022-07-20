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
    int tot;
    int findTilt(TreeNode* root) {
        tot=0;
        findSum(root);
        return tot;
        
        
    }
    
    int findSum(TreeNode* root){
        if(!root){
            return 0;
        }
        int sl=findSum(root->left);
        int sr=findSum(root->right);
        tot+=abs(sl-sr);
        return root->val+sl+sr;
    }
};