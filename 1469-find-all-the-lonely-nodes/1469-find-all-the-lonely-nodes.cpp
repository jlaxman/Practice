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
    vector<int> flatten(vector<int>& v1, vector<int>& v2){
        vector<int> ans;
        for(auto a: v1){
            ans.push_back(a);
        }
        for(auto a: v2){
            ans.push_back(a);
        }
        return ans;
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        if(!root) return {};
        
        vector<int> vec;
        if(root->right && root->left){
            auto v1=getLonelyNodes(root->left);
            auto v2=getLonelyNodes(root->right);
            return flatten(v1, v2);
            
        }else if(root->right==NULL && root->left){
            auto v1=getLonelyNodes(root->left);
            vector<int> temp;
            temp.push_back(root->left->val);
            return flatten(temp, v1);
        }
        else if(root->left==NULL && root->right){
            auto v1=getLonelyNodes(root->right);
            vector<int> temp;
            temp.push_back(root->right->val);
            return flatten(temp, v1);
        }
        return vec;
        
        
    }
};