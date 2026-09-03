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
    bool hasCycle(ListNode* head) {
        // if(head==nullptr || head->next==nullptr) return false; don't even need edge case here if 1) I check fast and fast->next 2) initilise slow and fast both to head in the beginning 3) and increment in loop before checking
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=(fast->next)->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};
