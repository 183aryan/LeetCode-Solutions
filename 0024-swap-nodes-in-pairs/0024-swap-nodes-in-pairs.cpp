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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0);
        ListNode* curr = head;
        ListNode* prev = temp;
        temp->next = head;
        
        while(curr != NULL and curr->next != NULL){
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            curr =  curr->next;
            prev = prev->next->next;
        }
        
        return temp->next;
    }
};