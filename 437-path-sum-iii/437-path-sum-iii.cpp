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
    int cnt;
    void noofPaths(TreeNode* root, long long ts){
       
        if(ts==0){
            cnt++;
        }
        if(root->left)  noofPaths(root->left, ts-root->left->val);
        if(root->right) noofPaths(root->right, ts-root->right->val);
    }
    void dfs(TreeNode* root, long long ts){
        if(root==NULL) return ;
        noofPaths(root, ts-root->val);
        dfs(root->left, ts);
        dfs(root->right, ts);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        cnt=0;
        dfs(root, 1LL*targetSum);
        return cnt;
        
    }
};