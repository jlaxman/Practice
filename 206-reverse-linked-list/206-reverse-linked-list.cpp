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
    ListNode* temp;
    void recurseRlist(ListNode* head){
        if(!head) return ;
        recurseRlist(head->next);
        if(head->next==NULL){
            temp=head;
        }else{
           head->next->next=head;
            head->next=NULL;
        }
    }
     
public:
    ListNode* reverseList(ListNode* head) {
        temp=NULL;
        recurseRlist(head);
        return temp;
    }
};