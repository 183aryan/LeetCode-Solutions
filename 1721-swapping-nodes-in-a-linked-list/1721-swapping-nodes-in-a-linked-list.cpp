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
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        
        ListNode* curr = head;
        while(curr!=NULL){
            cnt++;
            curr = curr->next;
        }
        curr = head;
        int cnt1 = 0;
        int first = k,second = cnt - k + 1;
        ListNode* s1,*s2;
        while(curr!=NULL){
            cnt1++;
            if(cnt1 == first){
                s1 = curr;
            }
            if(cnt1 == second){
                s2 = curr;
            }
            curr = curr->next;
        }
        swap(s1->val,s2->val);
        
        return head;
    }
};