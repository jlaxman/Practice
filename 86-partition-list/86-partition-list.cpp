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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode* sent= new ListNode(0);
        ListNode* sent2= new ListNode(0);
        ListNode* nhead=sent;
        ListNode* ghead=sent2;
        ListNode* ptr=head;
        
        while(ptr!=NULL){
            if(ptr->val<x){
                sent->next= new ListNode(ptr->val);
                sent=sent->next;  
            }else{
                sent2->next=new ListNode(ptr->val);
                sent2=sent2->next;  
            }
            ptr=ptr->next;
        }
        sent->next=ghead->next;
        return nhead->next;
        
    }
};