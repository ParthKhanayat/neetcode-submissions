# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

#iterative approach tc O(N) sc 0(1)
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev,curr=None,head
        while curr!=None:
            nxt=curr.next
            curr.next=prev
            prev=curr
            curr=nxt
        return prev