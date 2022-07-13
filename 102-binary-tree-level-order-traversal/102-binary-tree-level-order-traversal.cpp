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
    unordered_map<int, vector<int>> mpp;
    void preorder(TreeNode* root, int l){
        if(!root) return ;
        
        preorder(root->left, l+1);
        mpp[l].push_back(root->val);
        preorder(root->right, l+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        preorder(root, 0);
        int i=0;
        vector<vector<int>> ans;
        while(mpp.find(i)!=mpp.end()){
            ans.push_back(mpp[i]);
            i++;
        }
        return ans;
    }
};