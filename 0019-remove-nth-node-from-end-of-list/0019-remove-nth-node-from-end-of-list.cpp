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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p = head;
        for(int i=0;i<n;i++){
            p=p->next;
        }
        if(!p){
            head=head->next;
            return head;
        }
        ListNode * q = head;
        while(p->next!=NULL){
            p=p->next;
            q=q->next;
        }
        if(q->next == NULL){
            return head;
        }
        q->next = q->next->next;
        return head;
    
    }
};