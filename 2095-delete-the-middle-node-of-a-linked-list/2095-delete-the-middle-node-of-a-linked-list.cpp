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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL){
            delete head;
            return NULL;
        }
        ListNode* fast,*slow,*prev;
        fast = head;
        slow = head;
        prev = head;
        
        while(fast != NULL and fast->next != NULL){
            if(slow != head) prev = prev->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete(slow);
        
        return head;
    }
};