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
class Solution {
public:
    ListNode* front;
    bool recurseCheck(ListNode* head){
        if(head==NULL) return 1;
        bool subprblm= recurseCheck(head->next);
        bool curr= (head->val==front->val);
        front=front->next;
        return (subprblm && curr);
        
    }
public:
    bool isPalindrome(ListNode* head) {
        front=head;
        return recurseCheck(head);
    }
};