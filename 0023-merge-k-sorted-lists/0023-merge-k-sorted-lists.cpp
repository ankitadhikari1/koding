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
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val; // min-heap by value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;

        // push the head of each non-empty list
        for (auto& it : lists) {
            if (it) pq.push(it);
        }

        if (pq.empty()) return nullptr;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) pq.push(node->next);
        }

        tail->next = nullptr; // ensure termination
        return dummy.next;
    }
};
