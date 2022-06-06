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
        unordered_set<ListNode*> st;
        ListNode* ha=headA;
        ListNode* hb=headB;
        while(ha!=NULL){
            st.insert(ha);
            ha=ha->next;
        }
        while(hb!=NULL){
            if(st.find(hb)!=st.end()){
                break;
            }
            hb=hb->next;
        }
        return hb;
        
    }
};