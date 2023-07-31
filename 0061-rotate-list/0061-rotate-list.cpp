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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* t = head;
        // int len=0;
        // while(t != NULL){
        //     len++;
        //     t = t->next;
        // }
        // k = k%len;
        // for(int i=0;i<k;i++){
        //     ListNode* curr = head;
        //     while(curr->next->next != NULL) curr = curr->next;
        //     ListNode* x = curr->next;
        //     curr->next = NULL;
        //     x->next = head;
        //     head = x;
        // }
        // return head;
        int len=1;
        while(t->next){
            t = t->next;
            len++;
        }
        t->next = head;
        k %= len;
        k = len - k;
        while(k--) t = t->next;
        head = t->next;
        t->next = NULL;
        return head;
    }
};