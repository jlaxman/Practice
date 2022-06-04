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
    void inorder(TreeNode* root, vector<int>& vec){
        if(root==NULL) return ;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    TreeNode* generateBST(vector<int>& vec, int l, int r){
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* root= new TreeNode(vec[mid], generateBST(vec, l, mid-1), generateBST(vec, mid+1, r));
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        return generateBST(vec, 0, vec.size()-1);
    }
    
};