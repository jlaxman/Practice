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
    unordered_map<int, int> mpp;
    TreeNode* binaryTree(int lp, int rp, int li, int ri,vector<int>& pre, vector<int>& in){
        if(lp>rp || li>ri) return NULL;
        
        TreeNode* root= new TreeNode(pre[lp]);
        int ind= mpp[pre[lp]];
        int l= ind-li;
        int r= ri-ind;
        root->left= binaryTree(lp+1, lp+l, li, ind-1, pre, in);
        root->right=binaryTree(rp-r+1, rp, ind+1, ri, pre, in);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        
        for(int i=0;i<n; i++){
            mpp[in[i]]=i;
        }
        return binaryTree(0, n-1, 0, n-1, pre, in);
        
    }
};