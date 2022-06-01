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
    vector<int> temp;
    void fun(TreeNode* root){   
        
        if(!root) return ;
        if(root->right && root->left){
            fun(root->left);
            fun(root->right); 
        }else if(root->right==NULL && root->left){
            fun(root->left);
            temp.push_back(root->left->val);    
        }
        else if(root->left==NULL && root->right){
            fun(root->right);
            temp.push_back(root->right->val);
        }
        return ;
    }
        
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        temp.clear();
        fun(root);
        return temp;
        
    }
};