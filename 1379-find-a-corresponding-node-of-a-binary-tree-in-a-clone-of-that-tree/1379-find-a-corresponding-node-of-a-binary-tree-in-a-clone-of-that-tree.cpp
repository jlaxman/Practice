/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

public:
    TreeNode* fun(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==NULL) return NULL;
        if(original==target){
           
            return cloned;
        }
        TreeNode* le=fun(original->left, cloned->left, target);
        
        if(le!=NULL) return le;
        TreeNode* re=fun(original->right, cloned->right, target);
        if(re!=NULL) return re;
        return NULL;
        
        
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        return fun(original, cloned, target);
    }
};