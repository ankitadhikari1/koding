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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next )return head;
        ListNode * p = head->next;
        ListNode * q = head;
        while(p){
            int gcd = __gcd(p->val,q->val);
            ListNode * temp = new ListNode(gcd);
            temp->next = p;
            q->next = temp;

            p = p->next;
            q = temp->next;
        }

        return head;
    }
};