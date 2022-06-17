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
    //Greedy
    // int c;
    // int postOrder(TreeNode* root){
    //     if(root==NULL) return 1;
    //     int l=postOrder(root->left);
    //     int r= postOrder(root->right);
    //     if(l==0 || r==0){
    //         c++;
    //         return 2;
    //     }
    //     if(l==1 && r==1){
    //         return 0;
    //     }
    //     if(l==2 || r==2){
    //         return 1;
    //     }
    //     return 0;
    // }
    
    map<pair<pair<int, int>, TreeNode*>, int > mpp;
    int minCams(TreeNode* root, int place, int par){
        if(root==NULL){
            if(place){
                return 1e7;
            }else{
                return 0;
            }
        }
        if(mpp.find({{place, par}, root})!=mpp.end()) return mpp[{{place, par}, root}];
        if(root->left==NULL && root->right==NULL){
          if(place){
              return 1;
          }else{
              if(par) return 0;
              else return 1e7;
          }
        }
        int ans=1e7;
        if(place==1){
            ans= 1+ min(minCams(root->left, 0, 1), minCams(root->left, 1, 1))+min(minCams(root->right, 0, 1), minCams(root->right, 1, 1));
        }else{
            if(par==0){
                ans= min(minCams(root->left, 1, 0)+min(minCams(root->right, 0, 0), minCams(root->right, 1, 0)), minCams(root->right, 1, 0)+min(minCams(root->left, 0, 0), minCams(root->left, 1, 0)));
            }else{
                ans=min(minCams(root->left, 0, 0), minCams(root->left, 1, 0))+min(minCams(root->right, 0, 0), minCams(root->right, 1, 0));
            }
        }
        return mpp[{{place, par}, root}]=ans;
        
        
        
        
        
    }
    
public:
    int minCameraCover(TreeNode* root) {
        // c=0;
        // if(postOrder(root)==0) c++;
        // return c;
        
        return min(minCams(root, 0, 0), minCams(root, 1, 0));
        
       
    }
};