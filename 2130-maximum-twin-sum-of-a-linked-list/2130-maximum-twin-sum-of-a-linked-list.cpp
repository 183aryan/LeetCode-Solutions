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
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        int n = v.size();
       int sum = 0,new_sum = INT_MIN;
        for(int i=0;i<n/2;i++){
            sum = v[i] + v[n-i-1];
            if(new_sum<=sum){
                new_sum = sum;
            }
        }
        return new_sum;
    }
};