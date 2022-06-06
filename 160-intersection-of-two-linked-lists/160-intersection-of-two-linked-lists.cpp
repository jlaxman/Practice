/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ha=headA;
        ListNode* hb=headB;
        int cnta=0;
        int cntb=0;
        while(ha!=NULL){
            cnta++;
            ha=ha->next;
        }
        while(hb!=NULL){
            cntb++;
            hb=hb->next;
        }
        if(cnta< cntb){
            hb=headB;
            ha=headA;
            ListNode* d=NULL;
            int cnt=0;
            while(hb!=NULL){
                cnt++;
                if(cnt==cnta){
                    d=headB;
                }
                if(cnt>cnta){
                    d=d->next;
                }
                hb=hb->next;
            }
            
            while(ha!=d){
                ha=ha->next;
                d=d->next;
            }
            return ha;
        }else{
            hb=headB;
            ha=headA;
            ListNode* d=NULL;
            int cnt=0;
            while(ha!=NULL){
                cnt++;
                if(cnt==cntb){
                    d=headA;
                }
                if(cnt>cntb){
                    d=d->next;
                }
                ha=ha->next;
            }
            
            while(hb!=d){
                hb=hb->next;
                d=d->next;
            }
            return hb;
        }
        
    }
};