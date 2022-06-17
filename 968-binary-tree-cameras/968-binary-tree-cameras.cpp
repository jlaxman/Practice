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
    int c;
    int postOrder(TreeNode* root){
        if(root==NULL) return 1;
        int l=postOrder(root->left);
        int r= postOrder(root->right);
        if(l==0 || r==0){
            c++;
            return 2;
        }
        if(l==1 && r==1){
            return 0;
        }
        if(l==2 || r==2){
            return 1;
        }
        return 0;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        c=0;
        if(postOrder(root)==0) c++;
        return c;
        
       
    }
};