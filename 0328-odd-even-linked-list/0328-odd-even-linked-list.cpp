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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return head;
        }
        ListNode * slow = head;
        ListNode * fast = head->next;
        ListNode * head2 = fast;

        while(fast && fast->next){
            slow->next = fast ->next;
            fast->next = fast->next->next;
            slow = slow->next;
            fast = fast->next;
        }


        slow->next = head2;

        return head;
        
    }
};