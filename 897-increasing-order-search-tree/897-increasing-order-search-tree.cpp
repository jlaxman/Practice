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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vec;
        fun(root, vec);
        TreeNode* temp= NULL;
        for(int i=vec.size()-1; i>=0; i--){
            TreeNode* t1= new TreeNode();
            t1->val=vec[i];
            t1->right=temp;
            temp=t1;
        }
        return temp;
        
    }
    void fun(TreeNode* root , vector<int>& vec){
        if(!root) return ;
    
        fun(root->left, vec);
        vec.push_back(root->val);
        fun(root->right, vec);
        return ;
    }
        
};