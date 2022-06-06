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
       ListNode* fast= head;
       ListNode* slow= head;
       if(!head || !head->next) return 1;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* middle=slow;
        ListNode* second=middle;
        ListNode* dummy=NULL;
        while(second){
            ListNode* temp= second->next;
            second->next=dummy;
            dummy=second;
            second=temp;
        }
        fast=head;
        while(dummy){
            if(fast->val!=dummy->val) return 0;
            fast=fast->next;
            dummy=dummy->next;
        }
        return 1;
        
        
      
    }
};