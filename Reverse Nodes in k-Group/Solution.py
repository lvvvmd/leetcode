# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """

        tmp = head
        for i in range(k):
            if tmp == None:
                return head
            tmp = tmp.next
        tail = self.reverseKGroup(tmp, k)

        for i in range(k):
            tmp = head.next
            head.next = tail
            tail = head
            head = tmp
        
        return tail
