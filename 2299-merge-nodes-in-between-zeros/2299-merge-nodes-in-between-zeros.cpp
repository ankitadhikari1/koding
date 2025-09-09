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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * p = head->next;
        ListNode * q = p;
        while(q){
            int sum = 0;
            while(q->val!=0){
                sum+=q->val;
                q = q->next;
            }

            p->val = sum;
            q=q->next;
            p->next = q;
            p=p->next;
        }
        return head->next;
    }
};