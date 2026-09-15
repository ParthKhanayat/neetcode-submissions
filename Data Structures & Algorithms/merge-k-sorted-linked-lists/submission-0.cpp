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
private:
    ListNode* mergeTwoList(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val<=l2->val)
            {
                head->next=l1;
                l1=l1->next;
            }
            else
            {
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        if(l1==nullptr)
        {
            head->next=l2;
        }
        else
        {
            head->next=l1;
        }
        ListNode* res=dummy->next;
        delete dummy;
        return res;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size()>1)
        {
            vector<ListNode*> mergedLists;
            for(int i=0;i<lists.size();i=i+2)
            {
                ListNode* l1=lists[i];
                ListNode* l2=nullptr;
                if(i+1<lists.size()) l2=lists[i+1]; //check if the other list is in the bounds, because we can have odd no. of lists
                mergedLists.push_back(mergeTwoList(l1,l2));
            }
            lists=mergedLists;
        }
        return lists[0];
    }
};
