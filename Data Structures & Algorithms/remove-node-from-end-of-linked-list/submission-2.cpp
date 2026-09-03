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
        ListNode* dummy= new ListNode(-1,head); //stored in heap, never gets automatically cleared after program runs, therefor need to delte dummy also
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
        ListNode* newHead=dummy->next; //stays in stack, automatically gets cleared when program runs
        delete deleteNode;
        delete dummy;
        return newHead;
    }
};
