# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        small_list = ListNode(0)
        large_list = ListNode(0)
        small_head = small_list
        large_head = large_list

        while(head != None):
            if head.val >= x:
                large_list.next = ListNode(head.val)
                large_list = large_list.next
            else:
                small_list.next = ListNode(head.val)
                small_list = small_list.next
            head = head.next
            
        small_list.next = large_head.next
        return small_head.next
