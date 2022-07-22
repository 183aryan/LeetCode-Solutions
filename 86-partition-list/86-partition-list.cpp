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
        if(head == NULL || head->next == NULL) return head;  
        // vector<int> v;
        ListNode* curr;
        curr = head;
        
        ListNode* temp = new ListNode();
        ListNode* newnode = temp;
        while(curr!=NULL){
            if(curr->val < x){
                newnode->next = new ListNode(curr->val);
                newnode = newnode->next;
            }
            curr = curr->next;
        }
        
        curr = head;
        while(curr!=NULL){
            if(curr->val >= x){
                newnode->next = new ListNode(curr->val);
                newnode = newnode->next;
            }
            curr = curr->next;
        }
        return temp->next;
    }
};