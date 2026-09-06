/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//More Optimal Solution without using hashmap
// TC: O(3N), SC: O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //edge case:
        if(!head) return nullptr;
        //1) Insert copy nodes in between
        Node* temp=head;
        while(temp!=nullptr)
        {
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=copyNode->next;
        }

        //2) Connecting Random Pointers
        temp=head;
        while(temp!=nullptr)
        {
            Node* copyNode=temp->next;
            if(temp->random!=nullptr)
            {
                copyNode->random=(temp->random)->next; //copy of random
            }
            else
            {
                copyNode->random=nullptr;
            }
            temp=(temp->next)->next;

        }

        //3) Connecting Next Pointers
        Node* dummyNode= new Node(-1);
        Node* res=dummyNode;
        temp=head;
        while(temp!=nullptr)
        {
            res->next=temp->next;
            temp->next=(temp->next)->next;
            res=res->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }
};
