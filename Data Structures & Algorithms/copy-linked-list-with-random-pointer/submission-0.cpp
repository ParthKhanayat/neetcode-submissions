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

//Hashmap solution TC=O(2N) , SC=O(2N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        //base case:
        if(!head) return nullptr;
        unordered_map<Node*,Node*> mpp;
        //creating new nodes and putting temp in hashmap <original,copy>
        while(temp!=nullptr)
        {
            Node* newNode= new Node(temp->val);
            mpp.insert({temp,newNode});
            temp=temp->next;
        }
        temp=head;
        //connecting next and random of the new nodes
        while(temp!=nullptr)
        {
            Node* copyNode=mpp[temp];
            copyNode->next=mpp[temp->next];
            copyNode->random=mpp[temp->random];
            temp=temp->next;
        }

        return mpp[head];
    }
};
