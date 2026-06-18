# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy=ListNode() #this is how you create empty node(object) in python
        tail=dummy
        while list1 and list2 :
            if list1.val<list2.val:
                tail.next=list1
                list1=list1.next
            else:
                tail.next=list2
                list2=list2.next
            tail=tail.next
        if list1:
            tail.next=list1 #if l1 is remaining
        if list2:
            tail.next=list2 #if l2 is remaining
        #only either one of them will remain or none(equal length)
        return dummy.next
