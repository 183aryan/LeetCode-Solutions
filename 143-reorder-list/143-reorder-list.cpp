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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL){
            st.push(curr);
            len++;
            curr = curr->next;
        }
        curr = head;
        for(int i=0;i<len/2;i++){
            ListNode* x = st.top();
            st.pop();
            x->next = curr->next;
            curr->next = x;
            curr = curr->next->next;
        }
        curr->next = NULL;
    }
};