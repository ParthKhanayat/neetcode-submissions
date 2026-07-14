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

//iterative approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(curr!=nullptr)
        {   
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            // curr=curr->next; notice we assigned curr->next to previous so we can't move forward with this
            //so we will use a temporary variable for this
            curr=nxt;
        }
        return prev; //when this loop stops executing, the curr is nullptr so we return prev as the new HEAD
    
    }
};
