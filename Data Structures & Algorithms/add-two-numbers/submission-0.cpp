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
        ListNode* dummy= new ListNode(-1);
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* currNode=dummy;
        int carry=0;
        while(!(t1==nullptr && t2==nullptr))
        {
            int v1=0;
            int v2=0;
            if(t1!=nullptr) v1=t1->val;
            if(t2!=nullptr) v2=t2->val;
            int sum=v1+v2+carry;
            carry=sum/10; //a carry can never be greater than 10
            sum=sum%10; //extracts the current digit
            ListNode* newNode=new ListNode(sum);
            currNode->next=newNode;
            currNode=currNode->next;
            if(t1!=nullptr) t1=t1->next;
            if(t2!=nullptr) t2=t2->next;
        }
        if(carry>0)
        {
            ListNode* carryNode=new ListNode(carry);
            currNode->next=carryNode;
        }
        return dummy->next;
    }
};
