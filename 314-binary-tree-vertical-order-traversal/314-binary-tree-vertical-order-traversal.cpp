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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<pair< pair<int, int>, int>> ans;
        if(!root) return {};
        
        queue<pair<pair<int, int>,TreeNode* >> q;
        q.push({{0, 0},root});
        ans.push_back({{0, 0},0});
        unordered_map<int, int> mpp;
        int n=0;
        mpp[0]=root->val;
        while(!q.empty()){
            auto nodePair= q.front();
            q.pop();
            TreeNode* node=nodePair.second;
            int coln=nodePair.first.first;
            int rown=nodePair.first.second;
            if(node->left){
                n++;
                q.push({{coln-1, rown+1},node->left});
                ans.push_back({{coln-1, rown+1}, n});
                mpp[n]=node->left->val;
            }
            if(node->right){
                n++;
                q.push({{coln+1, rown+1},node->right});
                ans.push_back({{coln+1, rown+1}, n});
                mpp[n]=node->right->val;
            }
        }
        
        sort(ans.begin(), ans.end());
        vector<vector<int>> res;
        for(int i=0; i<ans.size(); i++){
            vector<int> temp;
            int col=ans[i].first.first;
            while(i<ans.size() && ans[i].first.first==col){
                temp.push_back(mpp[ans[i].second]);
                i++;
            }
            i--;
            res.push_back(temp);
        }
       
        return res;
        
    }
};