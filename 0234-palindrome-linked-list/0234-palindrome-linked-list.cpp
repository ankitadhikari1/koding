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
    ListNode *reverse(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *p=head;
        ListNode *q=NULL;
        while(p) {
            ListNode *r=p->next;
            p->next=q; 
            q=p;
            p=r;
        }
        return q;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *mid=slow;
        mid = reverse(mid);
        ListNode *start=head;
        while(start && mid) {
            if((start->val)!= (mid->val)) return false;
            start=start->next;
            mid=mid->next;
        }
        return true;

    }
};