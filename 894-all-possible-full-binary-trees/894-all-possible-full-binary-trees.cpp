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
    unordered_map<int, vector<TreeNode*>> mpp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1){
            TreeNode* temp= new TreeNode(0);         
            temp->left=NULL;
            temp->right=NULL;
            return {temp};
        }
        if(n%2==0) return {};
        if(mpp[n].size()) return mpp[n];
        vector<TreeNode*> ans;
       
        for(int i=1; i<=n-2; i+=2){
            vector<TreeNode*> left=allPossibleFBT(i);
             vector<TreeNode*> right=allPossibleFBT(n-i-1);
            
            for(auto tl: left){
                for(auto tr: right){
                    TreeNode* temp= new TreeNode(0);
                    temp->left= tl;
                    temp->right=tr;
                    ans.push_back(temp);
                }
            }
            
        }
        return mpp[n]=ans;
        
        
    }
};