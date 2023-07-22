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
    bool isPalindrome(ListNode* head) {
         ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL && fast->next == NULL){
            slow = slow->next;
        }
        
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(slow){
            temp = slow->next;
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        slow = prev;
        fast = head;
        while (slow){
           if (fast->val != slow->val) return false;
           fast = fast->next, slow = slow->next;
        }
        return true;
    }
};