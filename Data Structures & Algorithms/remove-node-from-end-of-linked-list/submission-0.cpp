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

 //SLOW AND FAST POINTER
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        int temp=n;
        while(fast!=nullptr)
        {
            if(temp==0)
            {
                break;
            }
            temp--;
            fast=fast->next; //we are already moving fast n steps ahead of slow, that means slow will exactly reach n steps behind end when we iterate them normally in next loop
        }
        //edge case: if head needs to be deleted
        if(fast==nullptr)
        {
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        while(fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delNode=slow->next;
        slow->next=(slow->next)->next;
        delete delNode;
        return head;
    }
};