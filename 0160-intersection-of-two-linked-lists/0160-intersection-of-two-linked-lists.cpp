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
        ListNode *currA = headA;
        ListNode *currB = headB;
        
        int cA = 0, cB = 0 ;
        
        while(currA != NULL){
            cA++;
            currA = currA->next;
        }
        while(currB != NULL){
            cB++;
            currB = currB->next;
        }
        
        int d = abs(cA-cB);
        currA = headA;
        currB = headB;
        if(cA > cB){
            for(int i=0;i<d;i++) currA = currA->next;
        }
        else{
           for(int i=0;i<d;i++) currB = currB->next;
        }
        
        while(currA != NULL and currB != NULL){
            if(currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
};