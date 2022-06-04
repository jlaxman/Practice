/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    bool startPath(ListNode* head, TreeNode* root){
        if(head==NULL) return 1;
        if(root==NULL) return 0;
        if(head->val != root->val) return 0;
        else{
            return startPath(head->next, root->left) || startPath(head->next, root->right);
        }
    }
    bool checkSubpath(ListNode* head, TreeNode* root){
        if(!root) return 0;
        return startPath(head, root) || checkSubpath(head, root->left) || checkSubpath(head, root->right); 
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(!head) return 1;
        return checkSubpath(head, root);
        
    }
};