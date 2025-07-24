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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)return NULL;
        if(!l1)return l2;
        if(!l2)return l1;

        ListNode * p = l1;
        ListNode * q = l2;
        ListNode * ans = new ListNode(0);
        ListNode * r = ans;
        int carry = 0;
        while((p || q)||carry){
            int sum = 0;
            if(p){
                sum+=p->val;
                p=p->next;
            }
            if(q){
                sum+=q->val;
                q=q->next;
            }
            sum+=carry;
            carry = sum / 10;
            ListNode * temp = new ListNode(sum%10);
            r->next = temp;
            r=r->next;
        }

        ans = ans->next;
        return ans;

    }
};