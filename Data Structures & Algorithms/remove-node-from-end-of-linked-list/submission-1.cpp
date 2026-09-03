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
        ListNode* dummy= new ListNode(-1,head);
        ListNode* l=dummy;
        ListNode* r=head;
        //now push r n postions forward
        while(n>0 && r!=nullptr)
        {
            r=r->next;
            n--;
        }
        while(r!=nullptr)
        {
            l=l->next;
            r=r->next;
        }
        ListNode* deleteNode=l->next;
        l->next=deleteNode->next;
        delete deleteNode;
        return dummy->next;
    }
};
