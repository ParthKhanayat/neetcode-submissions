# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        s,f=head,head
        while f and f.next: #we are shifting f by 2 that's why we need to check f.next also
            s=s.next
            f=f.next.next
            if s==f : return True #check after shifting, DON'T check before shifting slow and fast
        return False